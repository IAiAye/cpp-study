#include <iostream>
#include <string>
using namespace std;

class Base
{

public:
    Base() { cout << "기반 클래스" << endl; }

    virtual void what() { cout << "기반 클래스의 what()" << endl; }
};

class Derived : public Base
{

public:
    Derived(): Base() { cout << "파생 클래스" << endl; }

    void what() { cout << "파생 클래스의 what()" << endl; }
};

int main()
{
    Base p;
    Derived c;

    Base* p_c = &c;
    Base* p_p = &p;

    cout << " == 실제 객체는 Base == " << endl;
    p_p->what();

    cout << " == 실제 객체는 Derived == " << endl;
    p_c->what(); // virtual keyword로 인해 원래는 Base 포인터에서 실행하는 what이었으므로 기반이 출력되었어야 했지만,
    // virtual을 추가해줌으로써 실제 base 객체가 맞는지 확인하고 what을 실행해주게 된다.
    // 따라서 이처럼 컴파일 시에는 정해지지 않고, 런타임시에 정해지는 일을 동적 바인딩이라고 한다.
    // 이러한 virtual을 써주기 위해선 기반, 파생 클래스의 멤버함수가 정확하게 꼴이 같아야 한다.

    return 0;
}