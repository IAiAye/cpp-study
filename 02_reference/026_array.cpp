#include <iostream>

int main()
{
    //int a,b;
    //int& arr[2] = {a, b}; //레퍼런스의 배열은 존재할 수 없다. 배열은 메모리를 차지하기때문에 레퍼런스는 메모리를 차지하지않는 것과 일치하지않음.

    int arr[3] = {1, 2, 3};
    int(&ref)[3] = arr; // 반대로 배열(arr)의 레퍼런스(ref)는 존재할 수 있다. 이때 레퍼런스로 선언할때 크기를 반드시 붙여줘야하는데 기존의 배열과 동일해야한다.

    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;

    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    return 0;
}