#include <iostream>
#include <array>

// 디폴트로 인자를 넣어줄 수 있다.
template <typename T, int num = 5>
T add_num(T t)
{
    return t + num;
}

template <typename T>
// std::array <int,5> &arr 과 같이 일일이 안써줘도 된다.
void print_array(const T &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int x = 3;
    // 템플릿 인자로 타입이 아니라 숫자 5를 넣어주고 있다.
    std::cout << "x : " << add_num(x) << std::endl;
    // std::cout << "x : " << add_num<int, 5>(x) << std::endl;

    std::array <int, 5> arr1 = {1, 2, 3, 4, 5};
    std::array <int, 6> arr2 = {1, 2, 3, 4, 5, 6};
    std::array <int, 7> arr3 = {1, 2, 3, 4, 5, 6, 7};

    print_array(arr1);
    print_array(arr2);
    print_array(arr3);

    return 0;
}