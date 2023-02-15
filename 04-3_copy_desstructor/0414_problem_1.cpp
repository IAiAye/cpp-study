#include <string.h>
#include <iostream>

using namespace std;

class String
{
private:
    char *str;
    int len;

public:
    String(char c, int n);
    String(const char *s);
    String(const String &s);
    ~String();

    void show_status();
    void add_string(const String &s);
    void copy_string(const String &s);
    int strlen();
};

String::String(char c, int n)
{
    len = n;
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        str[i] = c;
    }
}
String::String(const char *s) // 복사생성자를 이용하여 새로운 문자열로 생성.
{
    len = 0;
    while (s[len]){ len++; };
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        str[i] = s[i];
    }
}
String::String(const String &s)
{
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str); // delete해줄때 다른 주소로 받기위해.
}
String::~String()
{
    if (str) delete[] str;
}
void String::show_status()
{
    cout << "String : " << str << ", Len : " << len << endl;
}
void String::add_string(const String &s)
{
    int len_ = len + s.len;
    char *str_;
    str_ = new char[len_ + 1];
    for (int i = 0; i < len; i++)
    {
        str_[i] = str[i];
    }
    for (int i = 0; i < s.len; i++)
    {
        str_[i + len] = s.str[i];
    }
    delete[] str;
    str = str_;
    len = len_;
}
void String::copy_string(const String &s) // 기존 객체를 덮어씌울때.
{
    len = s.len;
    delete[] str;
    str = new char[len + 1];
    strcpy(str, s.str);  
}
int String::strlen()
{
    return len;
}
int main()
{
    String str1('a', 10);
    String str2("damn");
    String str3(str1);

    str1.show_status();
    str2.show_status();
    str3.show_status();

    str1.add_string(str2);
    str1.show_status();

    str1.add_string(str3);
    str1.show_status();

    str2.copy_string(str1);

    str2.show_status();

    cout << str2.strlen() << endl;
}