#include <iostream>
#include <string>

// 함수 템플릿도 가능하다
template <typename T>
T max(T& a, T& b)
{
    return a > b ? a : b;
}

int main()
{
    int a = 1, b = 2;
    // a, b의 타입을 알아서 보고 함수타입 T를 int로 변환
    std::cout << "Max (" << a << "," << b << ") ? : " << max(a, b) << std::endl;

    std::string s = "hello", t = "world";
    std::cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << std::endl;

    return 0;
}