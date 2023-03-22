#include <iostream>
using namespace std;

int tmp, gcd_value;

void gcd(int a, int b)
{
    if (a == 0)
    {
        gcd_value = b;
    }
    
    if (a > b) // a < b 가 되도록.
    {
        tmp = b;
        b = a;
        a = tmp;
    }
    if (a != 0)
    {
        tmp = a;
        a = b % a;
        b = tmp;
        gcd(a , b);
    }
}

int main()
{
    long long int a,b;
    cin >> a >> b;
    gcd(a,b);
    cout << a * b / gcd_value << '\n';
}