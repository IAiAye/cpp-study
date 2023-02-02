//지역 변수의 레퍼런스
#include <iostream>

int& function()
{
    int a = 2;
    return a;
}
// 위의 함수는 int& ref = a; 와 동일한데, 함수가 종료되면서 a가 메모리에서 사라지므로, 아무것도 남지 않는다.

int main()
{
    int b = function(); // 따라서 여기선 본체는 사라지고 별명만이 남은 것이다.
    std::cout << b << std::endl;
    b = 3;
    std::cout << b << std::endl;
    return 0;
}

//따라서 레퍼런스를 리턴하는 함수에서는 지역변수의 레퍼런스를 리턴하지 않도록 조심해야한다.