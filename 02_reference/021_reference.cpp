#include <iostream>

int change_val(int *p) //포인터 p에 주소값 전달
{
    *p = 3; //포인터 p를 통해 number를 참조하여 값 변경

    return 0;
}
/*
C에서는 변수를 기리킬 때, 포인터만 사용해야함.
하지만 C++에서는 다른 변수나 상수를 가릐키는 방법으로 참조자(레퍼런스)를 제공한다.
*/ 
int main()
{
    int number = -5;

    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;
}