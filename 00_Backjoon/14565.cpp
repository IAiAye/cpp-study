#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long n, a;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    
    return gcd (b, a % b);
}

pair<long long, pair<long long, long long>> EEu(long long a, long long b)
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
    
    return make_pair(r0, make_pair(x0, y0));
}

void Input()
{
    cin >> n >> a;
}

void Solution()
{
    // 덧셈역 구하기, a < n이기 때문에 a % n = a
    cout << n - a << ' ';

    // 곱셉역 구하기
    if (gcd(n, a) != 1)
        cout << -1 << '\n';
    else
        cout << EEu(a, n).second.first << '\n';
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