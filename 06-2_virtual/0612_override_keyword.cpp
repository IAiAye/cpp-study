#include <iostream>
#include <string>
using namespace std;

class Base
{
private:
    string s;

public:
    Base() : s("기반") { cout << "기반 클래스" << endl; }

    virtual void incorrect() { cout << "기반 클래스" << endl; }
};
class Derived : public Base
{
private:
    string s;

public:
    Derived() : Base(), s("파생") {}

    void incorrect() override{ cout << "파생 클래스" << endl; } // 따라서 override를 명시적으로 적어 오류를 발생시킬수 있다.
};


int main()
{
    Base p;
    Derived c;

    Base* p_p = &p;
    Base* p_c = &c;

    cout << " == 실제 객체는 Base == " << endl;
    p_p->incorrect();

    cout << " == 실제 객체는 Derived == " << endl;
    p_c->incorrect(); // 상수 함수로 선언되어 기반함수와 다르기때문에 virtual이 있어도 오버라이드가 되지않는다.
    return 0;
}