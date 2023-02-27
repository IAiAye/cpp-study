// 전위 / 후위 증감 연산자
/*
전위/후위 연산자 모두 operator++ 이기때문에 이를 구분하는 방법은

전위는 operator();
후위는 operator(int x);
이지만 단순히 구분을 위해 넣어놓은 것이다. 실제로는 인자를 받지 않는다.


A& operator++() //전위
{
    // A ++ 을 수행
    return *this;
}
A operator++(int) //후위, 후위 증감 연산자는 복사생성자를 호출하므로 전위보다 더 느리다.
{
    A temp(A);
    // A ++ 을 수행
    return temp;
}
*/

#include <iostream>

class Test
{
private:
    int x;

public:
    Test(int x) : x(x) {}
    Test(const Test& t) : x(t.x) {}

    Test& operator++()
    {
        x++;
        std::cout << "전위 증감 연산자" << std::endl;
        return *this;
    }

    Test operator++(int)
    {
        Test temp(*this);
        x++;
        std::cout << "후위 증감 연산자" << std::endl;
        return temp;
    }

    int get_x() const { return x; }
};

void func(const Test& t)
{
    std::cout << "x : " << t.get_x() << std::endl;
}

int main()
{
    Test t(3);

    func(++t);
    func(t++);
    std::cout << "x : " << t.get_x() << std::endl;
}