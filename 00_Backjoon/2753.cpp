#include <iostream>

int main()
{
    int year;
    std::cin >> year;

    if (year % 400 == 0)
    {
        std::cout << "1";
        return 0;
    }
    if (year % 100 == 0)
    {
        std::cout << "0";
        return 0;
    }
    if (year % 4 == 0)
    {
        std::cout << "1";
        return 0;
    }
    std::cout << "0";
    return 0;
}