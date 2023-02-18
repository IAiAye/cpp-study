#include <iostream>
#include <string.h>

using namespace std;
/*
int stringLen(const char* str) // strlen 역할을 하는 함수를 만드려 했으나 왜인지 객체함수를 많이 썼을때 1이 추가된다.
{
    int len, i = 0;
    while (str[i])
    {
        len++;
        i++;
        if (str[i] == '\0')
        {
            break;
        }
        
    }
    return len;
}
*/

class MyString
{
private:
    char* string_content; // 문자열 데이터를 가리키는 포인터, 직접 저장하지 않는 이유는 새로운 문자열이 들어올때 해제하고 새로 할당해주어야하는데 내부에 있으면 어렵기 때문이다.
    int string_length; // 문자열 길이
    int memory_capacity;
public:
    MyString(char c); // 문자 하나로 생성
    MyString(const char* str); // 문자열로부터 생성
    MyString(const MyString& str); // 복사 생성자
    ~MyString();

    int length() const;
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    MyString& assign(const char* str); // 다음과 같이 하면 str1.assign(str2).print() 와 같이 연결하여 사용할 수 있다.
    MyString& assign(const MyString& str);

    char at(int i) const;

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    MyString& erase(int loc, int num);
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

void MyString::reserve(int size) // 기존의 메모리 할당보다 더 큰 메모리를 할당해주려고 할 때.
{
    if (size > memory_capacity)
    {
        char *prev_string_content = string_content; // 원래 문자열을 가리키는 포인터 작성.

        string_content = new char[size]; // 새로운 메모리 할당.
        memory_capacity = size;

        for (int i = 0; i < string_length; i++)
        {
            string_content[i] = prev_string_content[i];
        }
        
        delete[] prev_string_content;
    }
    // 따라서 기존 메모리보다 작은 크기를 할당해주려 할때는 아무 동작도 하지 않는다.
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
    {// 할당 다시 해주기.
        delete[] string_content;

        string_content = new char[string_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
    string_length = str_length; // string_length까지만 print하기때문에 뒤에는 따로 초기화해주지 않아도 된다.

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
    if (loc < 0 or loc > string_length) { return *this; } //범위가 벗어나는 연산은 바로 종료.
    
    if (str.string_length + string_length > memory_capacity)
    {
        if (memory_capacity * 2 > string_length + str.string_length)
        {
            memory_capacity *= 2; // 이와 같이 처리를 함으로써, 한글자씩 조금씩 늘어날때, 메모리를 그때마다 할당하는 것을 방지할 수 있다.
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
    //초과하지 않는 경우, 동적 할당을 다시 해줄필요가 없다.

    for (int i = string_length - 1; i >= loc; i--)
    {// 뒤에서부터 옮겨서 안겹치게 하기.
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
    if (num < 0 or loc < 0 or loc > string_length) return *this;
    
    for (int i = loc + num; i < string_length; i++)
    {
        string_content[i - num] = string_content[i];
    }
    string_length -= num;
    return *this;
}


int main()
{
    MyString str1("Very Very Very Long String");
    MyString str2(" <Inserted string> ");
    
    cout << "String length : " << str1.length() << endl;
    cout << "Capacity : " << str1.capacity() << endl;

    str1.reserve(30);
    
    cout << "String length : " << str1.length() << endl;
    cout << "Capacity : " << str1.capacity() << endl;

    str1.println();

    str1.assign("Short String");

    cout << "String length : " << str1.length() << endl;
    cout << "Capacity : " << str1.capacity() << endl;
    
    str1.println();

    cout << "String at : " << str1.at(4) << endl;

    str1.insert(5,str2).println();
    
    cout << "String length : " << str1.length() << endl;
    cout << "Capacity : " << str1.capacity() << endl;

    str1.insert(5,str2).println();

    cout << "String length : " << str1.length() << endl;
    cout << "Capacity : " << str1.capacity() << endl;

    str1.erase(5, 19).println();
    
    cout << "String length : " << str1.length() << endl;
    cout << "Capacity : " << str1.capacity() << endl;
}