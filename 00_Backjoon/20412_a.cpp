#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long m, seed, x1, x2;

long long Power(long long a, long long n)
{
    if (n == 0)
        return 1;
    
    // 홀수라면
    if (n & 1)
        return a * Power(a, n - 1) % m;
    
    long long tmp = Power(a, n / 2);
    return tmp * tmp % m;
}

void Input()
{
    cin >> m >> seed >> x1 >> x2;
}

void Solution()
{
    long long a = (x1 - x2) * Power(seed - x1, m - 2) % m;
    if (a < 0)
        a += m;
    
    long long c = x1 - (a * seed) % m;
    if (c < 0)
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