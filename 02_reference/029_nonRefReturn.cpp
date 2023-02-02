// 함수의 값을 레퍼런스로 받기.
#include <iostream>

int fuction()
{
    int a = 5;
    return a;
}

int main()
{
    //int& c = fuction(); //앞선 예시와 같이 함수가 끝나면서 값이 사라지기때문에, 참조할 수 없다.
    const int& c = fuction();
/*
원칙적으로는 함수의 리턴값은 해당 문장이 끝나면 소멸되는 것이 정상이다.
하지만, 예외적으로 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장된다.
*/

    std::cout << c << std::endl;
    return 0;
}