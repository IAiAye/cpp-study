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
    Derived() : Base(), s("파생") // 기반의 생성자 먼저 호출.
    {
        cout << "파생 클래스" << endl;

        what(); // 파생 클래스이므로 what을 호출할 수 있다.
    }
    void what() { cout << s << endl; } // 2. 이를 방지하기 위해 파생 클래스에도 똑같은 이름의 함수를 선언해주면, 기반 클래스보다 파생 클래스에서 먼저 찾아 오버라이드 하게 된다.
};
int main()
{
    cout << " === 기반 클래스 생성 === " << endl;
    Base p;
    cout << " === 파생 클래스 생성 === " << endl;
    Derived c; // 1. 이때 호출되는 what은 기반 클래스의 what이므로 기반이 출력된다.

    return 0;
}