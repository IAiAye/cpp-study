#include <iostream>

class A
{
private:
    mutable int data_; // 하지만 멤버 변수를 mutable로 선언해준다면 const함수 내에서도 바꿀수 있다.

public:
    A(int data) : data_(data) {}
    void DoSomething(int x) const{
        data_ = x; // 불가능! const 함수 내에서 값을 바꾸는 것은 불가능하다.
    }

    void PrintData() const { std::cout << "data : " << data_ << std::endl; }    
};

int main()
{
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}
/*
이렇게 const를 굳이 Mutable을 쓰면서 써야하는 이유는
서버를 예를 들어보자면,
const로 유저의 정보를 받아오는 함수가 있다고 해보자.
이때 우리는 데이터베이스에서 매번 요청하면 시간이 오래걸리기때문에 캐쉬에서 불러오는 경우가 많은데,
캐쉬에 없다면 데베에서 불러와 캐쉬에 등록해주는 과정이 필요하다.
이때 const함수 안이므로 이 과정이 오류가 발생하는데 이때 캐쉬를 Mutable로 선언해주면 사용이 가능해진다.
*/