#include <iostream>
#include <string>

template <typename T>
struct Compare 
{
    bool operator()(const T& a, const T& b) const { return a < b; }
};

template <typename T, typename Comp = Compare<T>>
T Min(T a, T b) 
{
    Comp comp;
    if (comp(a, b)) 
    {
        return a;
    }
    return b;
}

int main() 
{
    int a = 3, b = 5;
    // 다음과 같이 compare을 굳이 안넣어도 되도록 디폴트 템플릿 인자를 위와 같이 설정해줄수 있다.
    //std::cout << "min : " << Min <int, Compare<int>>(a, b);
    std::cout << "Min " << a << " , " << b << " :: " << Min(a, b) << std::endl;

    std::string s1 = "abc", s2 = "def";
    std::cout << "Min " << s1 << " , " << s2 << " :: " << Min(s1, s2) << std::endl;

    return 0;
}