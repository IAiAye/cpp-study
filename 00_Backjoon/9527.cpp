#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

// 0000
// 0001 1 2 (1 * 2)
// 0010
// 0011 4 8 (2 * 4)
// 0100
// 0101
// 0110
// 0111 12 24 (3 * 8)
// 1000
// 1001
// 1010
// 1011
// 1100
// 1101
// 1110
// 1111 32 64 (4 * 16) 32 = 12 + 12 + 8

// 0~15
ll a, b;
ll d[55];

ll CountOne(ll x)
{
    ll ans = x & 1;
    for (ll i = 54; i > 0; i--)
    {
        if (x & (1LL << i))
        {
            ans += d[i - 1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }
    return ans;
}

void Input()
{
    cin >> a >> b;
}

void Solution()
{
    d[0] = 1;
    for (ll i = 1; i < 55; i++)
        d[i] = d[i - 1] * 2 + (1LL << i);

    cout << CountOne(b) - CountOne(a - 1) << '\n';
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