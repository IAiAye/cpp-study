//이항 연산자 : 피연산자로 두개를 취하는 연산자
// 어떤 임의의 연산자 @에 대해 a@b는 컴파일러에 의해
// *a.operator@(b); , *operator@(a, b); 중 가능한 경우로 택하여 처리한다.
// 이 때 전자는 클래스의 멤버 함수로써 사용되는 것이고, 후자는 클래스 외부에 정의된 일반적인 함수를 의미한다.

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

    friend Complex operator+(const Complex& a, const Complex& b); // friend로 선언하여 클래스 내부의 프라이빗 변수에 접근 가능하게 한다.
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

int main()
{
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a; // 다음은 정상적으로 작동하지만,
    a = a + a; // 다음은 작동하지 않는다. 이는 a.operator+(a); , operator+(a, a);가 둘다 가능하여 발생하는 모호함으로 발생된다.
    /*
    이때, 통상적으로 자기 자신을 리턴하지않는 이항연산자 (+, -, / , *)들은 모두 외부 함수로 선언하는 것이 원칙이고,
    자기 자신을 리턴하는 이항연산자 (+=, -=, /=) 들은 모두 멤버 함수로 선언하는 것이 원칙이다.
    
    따라서 멤버 함수로 선언된 operator+를 지워보자.
    */
    a.println();
}