// friend 키워드는 클래스 내부에서 다른 클래스나 함수들을 friend로 정의할 수 있는데, friend로 정의된 클래스나 함수들은 원래 클래스의 private로 정의된 변수나 함수들에 접근 가능.

class A
{
private:
    void private_func() {}
    int private_num;

    // B 는 A 의 친구!
    // 하지만 A에서는 B의 프라이빗 필드에 접근하지 못한다. 양방향으로 하고싶다면 따로 선언이 필요함.
    friend class B;

    // func 는 A 의 친구!
    friend void func();

public:
};

class B
{
private:
    
public:
    void b()
    {
        A a;

        //   private 함수의 필드지만 친구이기 때문에 접근이 가능하다.
        a.private_func();
        a.private_num = 2;
    }
};

void func()
{
    A a;

    //   private 함수의 필드지만 위와 마찬가지로 친구이기 때문에 접근이 가능하다.
    a.private_func();
    a.private_num = 2;
}

int main()
{
    //컴파일을 해보아도 프라이빗 필드에 접근하고 있지만 문제가 발생하지 않는다.
}