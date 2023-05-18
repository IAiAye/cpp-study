// 가변 길이 템플릿
#include <iostream>

template <typename T>
void print(T arg)
{
    std::cout << arg << std::endl;
}
// 다음과 같이 typename 다음에 ...이 오는 것을 템플릿 파라미터 팩이라고 부른다.
// 템플릿 파라미터 팩은 0개 이상의 템플릿 인자들을 나타낸다.
template <typename T, typename ... Types>
void print(T arg, Types... args)
{
    // 다음을 실행하면 arg1은 arg로 나머지 arg2, arg3.. 등은 아래의 args...으로 들어간다.
    std::cout << arg << ", ";
    // 따라서 print(arg2, arg3)와 같고, 이는 다시 이 함수를 재귀적으로 호출 한다.
    // 마지막 print(arg3)만 남아 하나만 호출될때는 위의 함수가 호출되게 된다.
    // 파라미터팩이 없는 함수가 우선순위가 높기 때문이다.
    print(args...);
}

int main()
{
    print(1, 3.1, "abc");
    print(1, 2, 3, 4, 5, 6, 7);

    return 0;
}