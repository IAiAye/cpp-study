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
    Base* p_p = &c;

    Derived* p_c = static_cast<Derived*>(p_p); // 실제로 c는 derived의 객체이기때문에 다운캐스팅을 해도 문제가 없기때문에, 강제적으로 형변환을 해보자.
    p_c->what();
    // 강제적인 형변환을 했을때, 문제없이 실행이 되지만, 이러한 강제적 다운캐스팅은 컴파일러가 오류가 찾아내기 매우 힘드므로 권장하지 않는다.
    // 따라서 이러한 상속관계간에 있는 캐스팅을 해주는 dynamic을 이용하여 캐스팅을 해주게 되면 컴파일러가 오류를 발생시킨다.

    return 0;
}