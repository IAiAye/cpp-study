#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
#define MOD 1000000007

int m;

ll Power(ll n , ll a)
{
    ll ret = 1;
    while (a)
    {
        if (a & 1)
            ret = ret * n % MOD;
        a = a / 2;
        n = n * n % MOD;
    }
    return ret;
}

void Input()
{
    cin >> m;
}

void Solution()
{
    ll ans = 0;
    while (m--)
    {
        int n, s;
        cin >> s >> n;
        ans += (n * (Power(s, MOD - 2))) % MOD;
    }
    cout << ans % MOD << '\n';
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