#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "abc"; 
    string t = "def"; 
    string s2 = s;

    cout << s << endl; // 컴파일러에선 C 형식 문자열로 인식된다. 인자를 const char * 로 받는것을 알 수 있다.
    cout << s << " 의 길이 : " << s.length() << endl;
    cout << s << " 뒤에 " << t << " 를 붙이면 " << s + t << endl;

    if (s == s2) // 연산자 오버로딩을 통해 잘 계산된다.
    {
        cout << s << " 와 " << s2 << " 는 같다. " << endl;
    }
    if (s != t)
    {
        cout << s << " 와 " << t << " 는 다르다. " << endl;
    }
    return 0;
}