#include <iostream>

class A
{
private:
    int x;

public:
    A(int c) : x(c) {
        std::cout << "1" << std::endl;
        std::cout << x << std::endl;
    }
    A(const A& a)
    {
        x = a.x;
        std::cout << "복사 생성" << std::endl;
    }
};

class B
{
private:
    A a;

public:
    B(int c) : a(c){
        std::cout << "2" << std::endl;
    }
    B(const B& b) : a(b.a) {
        std::cout << "5" << std::endl;
    }
    A get_A()
    {
        std::cout << "3" << std::endl;
        A temp(a);
        std::cout << "4" << std::endl;
        return temp;
    }
};

int main()
{
    B b(10);
    std::cout << "-------------" << std::endl;
    A a1 = b.get_A();
}