#include <iostream>

int main()
{
    int x;
    int& y = x; // y는 x의 참조자
    int& z = y; // z는 y의 참조자이지만, 결국 x의 참조자가 됨.

    x = 1;
    std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;

    y = 2;
    std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;

    z = 3;
    std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;

    return 0;
}