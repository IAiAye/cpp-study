// virtual 소멸자
#include <iostream>
using namespace std;
class Parent
{
private:
    
public:
    Parent() { cout << "Parent 생성자 호출" << endl; }
    virtual ~Parent() { cout << "Parent 소멸자 호출" << endl; }
};

class Child : public Parent
{
private:
    
public:
    Child() : Parent() { cout << "Child 생성자 호출" << endl; }
    ~Child() { cout << "Child 소멸자 호출" << endl; }
};
int main()
{
    cout << "--- 평범한 child 만들었을 때 ---" << endl;
    { Child c; }
    cout << "--- Parent 포인터로 Child를 가리켰을 때 ---" << endl;
    {
        Parent *p = new Child();
        delete p; // delete p를 할때 부모의 소멸자가 호출되고, 자식의 소멸자가 호출되지 않는다. 이를 방지하기 위해 virtual을 사용한다.
    }
}