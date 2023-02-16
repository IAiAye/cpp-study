#include <iostream>

int main()
{
    int a,b;
    std::cin >> a >> b;
    int b_1, b_10, b_100;
    b_1 = b % 10;
    b_100 = b / 100;
    b_10 = (b - b_100 * 100 - b_1) / 10;

    std::cout << a * b_1 << std::endl;
    std::cout << a * b_10 << std::endl;
    std::cout << a * b_100 << std::endl;
    std::cout << a * b << std::endl;
    return 0;
}