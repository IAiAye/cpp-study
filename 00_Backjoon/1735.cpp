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
    int a,b;
    int c,d;
    cin >> a >> b >> c >> d;
    int up = (a * d + b * c);
    int down = b * d;
    gcd(up, down);
    cout << up / gcd_value << ' ' << down / gcd_value << '\n';
}