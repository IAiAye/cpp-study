// 외부 변수의 레퍼런스

#include <iostream>

int& function(int& a)
{
    a = 5;
    return a;
}

int main()
{
    int b = 2;
    int c = function(b); // b의 ref인 a를 5로 바꿔주어 b도 5가 되고, 참조자인 a를 return 받았으므로 c 도 5가 된다.
    std::cout << c << std::endl;
    return 0;
}

/*
이러한 참조자를 리턴해주는 것은 큰 구조체의 변수를 리턴하면 시간이 오래걸리지만, 해당 구조체의 레퍼런스를 리턴하면 주소값만 전달해주기때문에 효율적이다.
*/