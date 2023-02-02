#include <iostream>

int main()
{
    int a = 3;
    int& another_a = a; //a를 호출할 수 있는 또다른 참조자 another_a를 생성.

    std::cout << "a : " << a << std::endl;

    another_a =  5; //another_a를 수정했지만, a를 바꾼 것과 동일하다.

    std::cout << "a : " << a << std::endl;
    std::cout << "another_a : " << another_a << std::endl;

    return 0;
}

/*
레퍼런스와 포인터의 차이.
1. 레퍼런스는 단독으로 선언될수 없고, 누구의 별명이 될 것인지 명시해야한다.
2. 레퍼런스는 한번 선언이 되면, 다른이의 별명이 될 수 없다. (포인터는 자유롭게 가르키는 대상을 바꿀 수 있다.)
3. 레퍼런스는 메모리상에 존재하지 않을 수도 있다.
*/