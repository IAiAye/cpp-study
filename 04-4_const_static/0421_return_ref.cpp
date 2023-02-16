//레퍼런스를 리턴하는 함수
#include <iostream>

class A
{
private:
    int x;
public:
    A(int c) : x(c) {}

    int& access_x() { return x; } // ref 리턴
    int get_x() { return x; } // 값 리턴
    void show_x() { std::cout << x << std::endl; }
};

int main()
{
    A a(5);
    a.show_x();

    int& c = a.access_x(); // c는 x의 별명으로 탄생.
    c = 4;
    a.show_x();;

    int d = a.access_x(); // d에 단순히 별명을 전달.
    d = 3;
    a.show_x();

    int f = a.get_x();
    std::cout << f << std::endl;
    f = 1;
    a.show_x();

    // 오류
    //int& e = a.get_x(); get_x 는 임시객체로 존재하면서 x값을 전달해주는데, 레퍼런스는 임시객체를 참조하지 못하므로 오류가 발생한다.
    //e = 2;
    //a.show_x();
}
