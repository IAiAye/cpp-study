#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
private:
    char* string_content; 
    int string_length; 
    int memory_capacity;
public:
    MyString(char c); 
    MyString(const char* str); 
    MyString(const MyString& str); 
    ~MyString();

    int length() const;
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    MyString& assign(const char* str); 
    MyString& assign(const MyString& str);

    char at(int i) const;

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    MyString& erase(int loc, int num);

    int find(int find_from, const MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const; // 숫자로 값을 반환하는 것보다 직접 연산자를 통해 비교하는 것이 직관적이다.
    bool operator==(MyString& str); // 이를 통해 str1 == str2의 연산이 가능하다.
};

MyString::MyString(char c)
{
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
    memory_capacity = string_length;
}
MyString::MyString(const char* str)
{
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str)
{
    string_length = str.string_length;
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}
MyString::~MyString(){ delete[] string_content; }

int MyString::length() const { return string_length; }
int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) 
{
    if (size > memory_capacity)
    {
        char *prev_string_content = string_content; 

        string_content = new char[size]; 
        memory_capacity = size;

        for (int i = 0; i < string_length; i++)
        {
            string_content[i] = prev_string_content[i];
        }
        
        delete[] prev_string_content;
    }
    
}

void MyString::print() const
{
    for (int i = 0; i != string_length; i++)
    {
        cout << string_content[i];
    }
}
void MyString::println() const
{
    for (int i = 0; i != string_length; i++)
    {
        cout << string_content[i];
    }
    cout << endl;
}
MyString& MyString::assign(const char* str)
{
    int str_length = strlen(str);
    if (str_length > memory_capacity)
    {
        delete[] string_content;

        string_content = new char[string_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
    string_length = str_length; 

    return *this;
}
MyString& MyString::assign(const MyString& str)
{
    if (str.string_length > memory_capacity)
    {
        delete[] string_content;
        
        string_content = new char[str.string_length];    
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];

    string_length = str.string_length;

    return *this;
}
char MyString::at(int i) const
{
    if (i >= string_length or i < 0)
    {
        return 0;
    }
    return string_content[i];
}
MyString& MyString::insert(int loc, const MyString& str)
{
    if (loc < 0 or loc > string_length) { return *this; } 
    
    if (str.string_length + string_length > memory_capacity)
    {
        if (memory_capacity * 2 > string_length + str.string_length)
        {
            memory_capacity *= 2; 
        }
        else
        {
            memory_capacity = string_length + str.string_length;
        }

        char *prev_string_content = string_content;
        string_content = new char[memory_capacity];

        int i;
        for (i = 0; i != loc; i++)
        {
            string_content[i] = prev_string_content[i];
        }
        for (int j = 0; j != str.string_length ; j++)
        {
            string_content[j + i] = str.string_content[j];
        }
        for (; i != string_length ; i++)
        {
            string_content[i + str.string_length] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length += str.string_length;
        return *this;
    }
    

    for (int i = string_length - 1; i >= loc; i--)
    {
        string_content[i + str.string_length] = string_content[i];
    }
    for (int i = 0; i < str.string_length; i++)
    {
        string_content[i + loc] = str.string_content[i];
    }
    string_length += str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, const char* str)
{
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c)
{
    MyString temp(c);
    return insert(loc, temp);
}
MyString& MyString::erase(int loc, int num)
{
    if (num < 0 or loc < 0  or loc + num > string_length) return *this;
    
    for (int i = loc + num; i < string_length; i++)
    {
        string_content[i - num] = string_content[i];
    }
    string_length -= num;
    return *this;
}
int MyString::find(int find_from, const MyString& str) const
{
    int i, j;
    if (str.string_length == 0) return -1;
    for (i = find_from; i <= string_length - str.string_length; i++)
    {
        for (j = 0; j < str.string_length; j++)
        {
            if (string_content[i + j] != str.string_content[j])
            {
                break;
            }
        }
        if (j == str.string_length)
        {
            return i;
        }
    }
    return -1;
}
int MyString::find(int find_from, const char* str) const
{
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const
{
    MyString temp(c);
    return find(find_from, temp);
}
int MyString::compare(const MyString& str) const
{ 
    for (int i = 0; i < min(string_length, str.string_length); i++)
    {
        if (string_content[i] < str.string_content[i]) return -1;
        if (string_content[i] > str.string_content[i]) return 1;
    }
    if (string_length == str.string_length) return 0;
    else if (string_length < str.string_length)
    {
        return -1;
    }

    return 1;
}
bool MyString::operator==(MyString& str)
{
    return !compare(str); // str과 같으면 compare에서 0을 리턴하기때문에 !을 붙여준다.
}

int main()
{
    MyString str1("a word");
    MyString str2("sentence");
    MyString str3("sentence");

    if (str1 == str2) cout << "str1 과 str2는 같다. \n"; // 이전엔 == 연산자를 사용하지 못했지만, 오버로딩을 통해 만들어주었다.
    else cout << "str1 과 str2는 다르다. \n";
    
    if (str2 == str3) cout << "str2 과 str3는 같다. \n";
    else cout << "str2 과 str3는 다르다. \n";   
}