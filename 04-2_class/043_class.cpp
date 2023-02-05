// 함수의 오버로딩

#include <iostream>

void print(int x){ std::cout << "int : " << x << std::endl; }
//void print(char x){ std::cout << "char : " << x << std::endl; }
// char 자료형을 받아주는 함수가 없어지면 정확히 일치하는 인자가 없어지므로 자신과 최대로 근접한 함수를 찾는다.

void print(double x){ std::cout << "double : " << x << std::endl; }

int main()
{
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);
    // 함수의 이름이 똑같아도 인자가 다르면 다른 함수로 판단한다.

    return 0;
}

/*
오버로딩 하는 과정.
1. 타입이 정확히 일치하는 함수를 찾는다.
2. 정확히 일치하는 타입이 없는 경우 아래와 같이 형변환을 통해서 일치하는 함수를 찾는다.
char, unsigned char, short -> int
unsigned short -> int or unsigned int
float -> double
enum -> int
3. 다음 과정을 거쳐도 일치하는 것이 없다면 더 포괄적으로 찾는다.
4. 유저 정의된 타입 변환으로 일치하는 것을 찾는다.

다음 과정을 거쳐서도 함수를 찾을수 없다면 오류 발생.
*/