#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
long long c, k;
long long MOD = 1000000007;

void Input()
{
    cin >> n;
}

void Solution()
{
    long long sum = 0;
    while(n--)
    {
        cin >> c >> k;
        long long res = 1, a = 2, b = k - 1;

        while (b)
        {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        sum = (sum + ((c * k) % MOD) * res) % MOD;
    }
    cout << sum << '\n';
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