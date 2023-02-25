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

    Complex operator+(const Complex& c) const; // 다음과 같은 오퍼레이터 오버로딩을 사용하지 않는다면 c1.plus(c1.minus(c2)와 같이 직관적이지 않은 연산을 해주어야한다.
    Complex operator-(const Complex& c) const; // return 타입이 Complex&가 아닌 Complex인데 사칙연산의 게산이 이루어질때 레퍼런스로 받게되면 이전의 값이 변화하는 경우가 있으므로 정확한 값으로 주는것이 맞다.
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    Complex operator+(const char* str) const;
    Complex operator-(const char* str) const;
    Complex operator*(const char* str) const;
    Complex operator/(const char* str) const;

    Complex& operator=(const Complex& c);

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);
    
    void println() { cout << "( " << real << ", " << img << " ) \n"; }
};
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
            num += (str[i] - '0'); // '2' - '0' = 2이므로 숫자로 표현해줄 수 있다.
        }
        else if (str[i] == '.') integer_part = false;
        else if (isdigit(str[i]) and !integer_part)
        {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        }
        else break; // 이외의 경우는 숫자와 . 이외의 문자뿐이다.
    }
    if (minus) num *= -1.0;

    return num;
}
Complex::Complex(const char* str)
{ //입력받은 문자열을 분석해 실수부와 허수부를 나누어야한다.
    int begin = 0, end = strlen(str);
    real = 0.0;
    img = 0.0;

    // i 찾기
    int pos_i = -1;
    for (int i = 0; i < end; i++)
    {
        if (str[i] == 'i')
        {
            pos_i = i;
            break;
        }
    }
    
    if (pos_i == -1) // 허수부가 없는 경우
    {
        real = get_number(str, begin, end - 1);
        return;
    }
    
    //i 가 있다면 실수부와 허수부를 나눠서 처리하기.
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 and str[pos_i - 1] == '-') img *= -1.0;
}

Complex Complex::operator+(const Complex& c) const
{
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) const
{
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) const
{
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) const
{
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}
Complex Complex::operator+(const char* str) const
{
    Complex temp(str);
    return (*this) + temp;
}
Complex Complex::operator-(const char* str) const
{
    Complex temp(str);
    return (*this) - temp;
}
Complex Complex::operator*(const char* str) const
{
    Complex temp(str);
    return (*this) * temp;
}
Complex Complex::operator/(const char* str) const
{
    Complex temp(str);
    return (*this) / temp;
}
Complex& Complex::operator=(const Complex& c)
{
    real = c.real;
    img = c.img;
    return *this;
}
Complex& Complex::operator+=(const Complex& c)
{
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c)
{
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c)
{
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c)
{
    (*this) = (*this) / c;
    return *this;
}

int main()
{
    Complex a(1.0, 2.0); //1 + 2j
    Complex b(3.0, -2.0); // 3 - 2j

    Complex c = a * b;

    a += b;

    a.println();
    c.println();

    b = b + "-3.5 + i2.2"; // 다음과 같은 식은 b.operator+("-3.5+i2.2")로 동작된다.
    // 따라서 "-3.5 + i2.2" + b 와 같이 표현을 해준다면 이는 오류가 발생하게 된다.
    b.println();

    b = b - "-3.5 + i2.2";
    b.println();

    b = b * "-3.5 + i2.2";
    b.println();

    b = b / "-3.5 + i2.2";
    b.println();

    
}