#include <iostream>
#include <string>
using namespace std;

class Base
{
private:
    string s;

public:
    Base() : s("기반") { cout << "기반 클래스" << endl; }

    void what() { cout << s << endl; }
};

class Derived : public Base
{
private:
    string s;

public:
    Derived() : s("파생"), Base() { cout << "파생 클래스" << endl; }

    void what() { cout << s << endl; }
};

int main()
{
    Base p;
    Derived c;

    cout << "=== 포인터 버전 ===" << endl;
    Base* p_c = &c; // derived 의 객체 c 를 base 를 가리키는 포인터 p_c에 대입했다.
    // 이는 derived is a base 이기때문에 가능하다.
    // 다만 derived 객체에서 base 부분만을 가리키기때문에 derived에서 추가한 정보에 대한 것은 가리키지 못한다.

    p_c->what();
    // 따라서 what() 함수를 호출했을때, 기반 클래스의 what이 호출되는 것을 볼 수 있다.
    // 이러한 캐스팅을 (파생에서 기반 클래스로의 캐스팅)을 업 캐스팅이라 한다.

    // Derived* p_p = &p; // 오류 발생

    // 이와 반대인 다운 캐스팅은 기반 클래스에 파생 클래스에 대한 정보가 없으므로 금지된다.
    return 0;
}