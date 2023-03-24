#include <iostream>
#include <sstream>

int main()
{
    std::istringstream ss("123"); // 문자열을 하나의 스트림이라고 생각하게 해준다.
    int x;
    ss >> x;

    std::cout << "입력 받은 데이터 :: " << x << std::endl;

    return 0;
}