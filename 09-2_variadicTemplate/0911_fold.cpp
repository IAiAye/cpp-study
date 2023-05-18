#include <iostream>

template <typename... Ints>
int sum_all(Ints... nums)
{
    // ... 이 fold 형식으로 재귀를 종료하기 위한 베이스케이스가 없어도 된다.
    // ((((1 + 4) + 2) + 3) + 10) 와 같은 식으로 계산을 해준다.
    // ...의 위치가 중요하다. 다음과 같은 경우는 단항 좌측 fold라 한다.
    return (... + nums);
}

template <typename Int, typename... Ints>
int diff_from(Int start, Ints... nums)
{
    // ...의 위치가 중요하다. 다음과 같은 경우는 이항 좌측 fold라 한다. start라는 초기값부터 시작
    // (((((100 - 1) - 4) - 2) - 3) - 10)
    return (start - ... - nums);
}

class A
{
public:
    void do_something(int x) const
    {
        std::cout << "Do something with " << x << std::endl;
    }
};

template <typename T, typename... Ints>
void do_many_things(const T& t, Ints... nums)
{
    // 각각의 인자들에 대해 do_something 함수를 호출한다.
    // , 연산자를 통해 각각의 인자들에 대해 원하는 식을 실행해주는 것이다.
    (t.do_something(nums), ...);
}

int main()
{
    std::cout << sum_all(1, 4, 2, 3, 10) << std::endl;
    std::cout << diff_from(100, 1, 4, 2, 3, 10) << std::endl;
    
    A a;
    do_many_things(a, 1, 3, 2, 4);
    return 0;
}