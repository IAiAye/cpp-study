//int Wrapper 클래스, 타입 변환 연산자
// 프로그래밍을 할때, 기본 자료형들을 객체로써 다루어야 할때가 있다.
// 이를 클래스로 포장하여 각각의 자료형을 객체로 사용하는 것을 Wrapper 클래스를 이용한다는 뜻이다.

/*
우리는 이 객체를
Int x = 3;
int a = x + 4;
와 같이 일반적인 int 자료형과 똑같이 작동하도록 만들고 싶다.
이를 위해 Int class 안에 모든 연산자를 오버로딩 해주어야 할까?

그럴 필요 없이 컴파일러에게 이 래퍼 클래스의 객체를 int형 변수라고 생각할 수 있게 만들 수 있다.
*/

#include <iostream>
class Int
{
private:
    int data;

public:
    Int(int data) : data(data) {}
    Int(const Int& i) : data(i.data) {}

    operator int() { return data; } // 이를 위한 타입 변환 연산자.
};

int main()
{
    Int x = 3;
    int a = x + 4;

    x = a * 2 + x + 4;
    std::cout << x << std::endl;
}