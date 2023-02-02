//new 로 배열 할당하기

#include <iostream>

int main()
{
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int *list = new int[arr_size]; //new []로 선언.
    for (int i = 0; i < arr_size; i++)
    {
        std::cout << i + 1 << " 번째 입력 : ";
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++)
    {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }
    delete[] list; //delete []로 할당 해제.
    return 0;
    
}