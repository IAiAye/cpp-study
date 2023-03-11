#include <iostream>
using namespace std;
class A
{
    public:
    virtual void show() { cout << "Parent!" << endl; }
};
class B : public A
{
    public:
    void show() override { cout << "Child!" << endl; }
};
void test(A& a) { a.show(); } // 클래스 A의 레퍼런스가 인자지만 파생 클래스인 B를 넣어도 제대로 작동한다.

int main()
{
    A a;
    B b;
    test(a);
    test(b);
    return 0;
}