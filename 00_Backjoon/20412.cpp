#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long m, seed, x1, x2;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    
    return gcd (b, a % b);
}

// a의 역원을 구한다. (mod b)
long long EEu(long long a, long long b)
{
    long long r0 = a, r1 = b;
    long long x0 = 1, x1 = 0;
    long long y0 = 0, y1 = 1;
    long long q;
    
    while (r1)
    {
        q = r0 / r1;

        r0 = r0 % r1;
        swap(r0, r1);

        x0 = x0 - q * x1;
        swap(x0, x1);
        x1 %= b;

        y0 = y0 - q * y1;
        swap(y0, y1);
        y1 %= a;
    }
    if (x0 <= 0)
    {
        x0 += b;
        y0 -= a;
    }
    
    return x0;
}

void Input()
{
    cin >> m >> seed >> x1 >> x2;
}

void Solution()
{
    long long minus_temp = x1 - x2;

    if (minus_temp == 0)
    {
        long long a = 2;
        long long c = m - seed;
        cout << a << ' ' << c << '\n';
        return;
    }

    while (minus_temp < 0)
        minus_temp += m;
    
    long long p = EEu(minus_temp, m);

    while (p < 0)
        p += m;
    
    minus_temp = (seed - x1) * p;
    while (minus_temp < 0)
        minus_temp += m;

    long long a = EEu(minus_temp, m);
    while (a < 0)
        a += m;
    
    long long c = -a * seed + x1;
    while (c < 0)
        c += m;

    cout << a << ' ' << c << '\n';
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}