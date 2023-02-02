#include <iostream>

int main()
{
    //int &ref = 4; // 리터럴을 참조하기때문에 오류 발생. ref를 바꾸면 리터럴이 바뀌기때문에.
    const int &ref = 4; // 다음과 같이 상수 참조자로 선언한다면 리터럴도 참조 가능.

    std::cout << ref << std::endl;

    int a = ref; // 리터럴을 참조한 모습.

    std::cout << a << std::endl;
}