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
    explicit MyString(int capacity); // explicit 를 추가해줌으로 인해 이 생성자를 이용한 암시적 변환을 수행하지 못하도록 막을 수 있다.

    MyString(const char* str); 

    MyString(const MyString& str); 

    ~MyString();

    int length() const;
    void println() const;
};

MyString::MyString(int capacity)
{
    memory_capacity = capacity;
    string_content = new char[memory_capacity];
    string_length = 0;
    cout << "Capacity : " << capacity << endl;
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

void MyString::println() const
{
    for (int i = 0; i != string_length; i++)
    {
        cout << string_content[i];
    }
    cout << endl;
}

void DoSomethingWithString(MyString s) // 클래스의 객체를 이용하는 다음과 같은 함수가 있다고 생각해보자.
{
    s.println();
}
int main()
{
    MyString s(3);
    DoSomethingWithString(MyString("abc")); // 다음은 당연히 클래스의 객체를 만들어서 넣었으므로 동작한다.
    DoSomethingWithString("DEFE"); // 하지만 다음은 클래스를 표시하지 않았지만, MyString(const char* str)라는 생성자가 있으므로 자동으로 변환하여 대입하게 된다.
    // 이를 암시적 변환 (implicit conversion)이라 부른다.
    //DoSomethingWithString(4); // 하지만 만약 우리가 실수로 문자 4를 넣기를 원했으나 숫자 4를 넣어도 자동으로 변환하여 생성자를 실행시켜준다.

    //이렇게 암시적 변환을 하지 못하게 명시해주는 방법이 explicit이다.

    MyString s1 = "abc"; // 다음과 같이 복사생성자의 형태로 호출되는 것도 막아준다.
    //MyString s2 = 5;
    MyString s3(5); // 다음과 같이 명시적으로 생성자를 부를때만 허용해준다.
}