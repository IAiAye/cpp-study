//입출력 연산자 오버로딩
// std::cout << a; 는
// std::cout.operator<<(a); 와 동일한 명령이다.
// 즉, std::cout 이라는 객체에 멤버함수 operator << 가 정의되어 있어 a를 호출하는 것이다.
// 이 때, 헤더파일 안에는 수많은 타입에 대해 모두 operator<< 가 오버로딩 되어있다.

// 따라서 우리의 complex 클래스도 operator<<를 통해 출력할 수 있게 해보자.

// 하지만, 헤더파일로 들어가 멤버 함수를 추가해줄수는 없으므로,
// 새로운 operator<< 전역함수를 정의해보자.

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class Complex
{
private:
    double real, img;
    double get_number(const char* str, int from, int to) const;

public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex& c) { real = c.real, img = c.img; }
    Complex(const char* str);

    Complex& operator=(const Complex& c);
    
    void println() { cout << "( " << real << ", " << img << " ) \n"; }

    friend Complex operator+(const Complex& a, const Complex& b); 
    friend ostream& operator<<(ostream& os, const Complex& c);
};

Complex operator+(const Complex& a, const Complex& b)
{
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;
}

double Complex::get_number(const char* str, int from, int to) const
{
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' or str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++)
    {
        if (isdigit(str[i]) and integer_part)
        {
            num *= 10.0;
            num += (str[i] - '0'); 
        }
        else if (str[i] == '.') integer_part = false;
        else if (isdigit(str[i]) and !integer_part)
        {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        }
        else break; 
    }
    if (minus) num *= -1.0;

    return num;
}
Complex::Complex(const char* str)
{ 
    int begin = 0, end = strlen(str);
    real = 0.0;
    img = 0.0;

    
    int pos_i = -1;
    for (int i = 0; i < end; i++)
    {
        if (str[i] == 'i')
        {
            pos_i = i;
            break;
        }
    }
    if (pos_i == -1) 
    {
        real = get_number(str, begin, end - 1);
        return;
    }
    
    
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 and str[pos_i - 1] == '-') img *= -1.0;
}

Complex& Complex::operator=(const Complex& c)
{
    real = c.real;
    img = c.img;
    return *this;
}
std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << " ( " << c.real << " , " << c.img << " ) "; // 프라이빗에 접근하지 못한다. 따라서 friend로 선언해준다.
    return os;
}


int main()
{
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a; 
    a = a + a; 

    cout << "a의 값은 : " << a << " 이다. " << endl;
}