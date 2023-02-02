//heap 에서만 가능.
#include <iostream>

int main()
{
    int* p = new int;
    // Type* pointer = new Type; type만큼의 공간을 할당하여 그 주소값을 p에 넣어줌.
    *p = 10;

    std::cout << *p << std::endl;

    delete p;
    // 할당된 공간 해제.
    return 0;
}