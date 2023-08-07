#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int n;
ll MOD = 1000000007;

vector<ll> arr;
ll sum;

ll Power(ll a, ll n)
{
    if (n == 0)
        return 1;
    
    ll tmp = Power(a, n / 2);
    if (n & 1)
        return a * tmp * tmp % MOD;
    else
        return tmp * tmp % MOD;
}

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
}

void Solution()
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll r = j - i - 1;
            sum += (((arr[j] - arr[i]) % MOD) * ((Power(2, r)) % MOD)) % MOD;
            sum %= MOD;
        }
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