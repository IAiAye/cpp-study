//모호한 오버로딩

#include <iostream>

void print(int x) { std::cout << " int : " << x << std::endl; }
void print(char x) { std::cout << " double : " << x << std::endl; }

int main()
{
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);
    // double은 1,2단계에서 일치하는 것이 없고, 3단계에서는 임의의 숫자 타입으로 변경되므로 char, int 둘다 가능해서 모호함 발생.

    return 0;
}