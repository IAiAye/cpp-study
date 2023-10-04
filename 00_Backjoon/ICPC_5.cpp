#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

ll tc, n;

ll phi(ll n)
{
    ll cnt = 0;
    ll ans = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
        ans = ans / n * (n - 1);

    return ans;
}


void Input()
{
    cin >> tc;
}

void Solution()
{
    while (tc--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        else if (n == 2)
        {
            cout << 1 << '\n';
            continue;
        }
        int ans;
        if (n % 2 == 0)
            ans = phi(n) + phi(n / 2);
        else
            ans = phi(n);
        
        cout << ans << '\n';
    }
    
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