#include <iostream>

int change_val(int &p) //참조자
{
    p = 3;

    return 0;
}

int main()
{
    int number = -5;

    std::cout << number << std::endl;
    change_val(number); //number 앞에 &를 붙이지 않는다.
    std::cout << number << std::endl;
}