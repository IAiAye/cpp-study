#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 2000001
#define MOD 1000000007
int n, m, k;
ll fac[MAX];
ll inv[MAX];
ll modInv[MAX];

vector<pair <int, int>> bomb;

bool cmp(pair <int, int>& a, pair <int, int>& b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

ll Power(ll a, ll b)
{
    if (b == 1)
        return a;
    if (b == 0)
        return 1;

    ll tmp = Power(a, b / 2);
    if (b & 1)
        return ((tmp * tmp % MOD) * a) % MOD;
    else
        return (tmp * tmp % MOD);
}

ll Comb(int n, int r)
{
    // cout << modInv[n - r] << ' ' << modInv[r] << '\n';
    return (((fac[n] * modInv[n - r]) % MOD) * modInv[r]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    fac[1] = 1;
    inv[1] = 1;
    modInv[1] = 1;

    for (ll i = 2; i < MAX; i++) 
    {
        fac[i] = (fac[i - 1] * i) % MOD;

        inv[i] = (-(MOD / i) * inv[MOD % i]) % MOD;
        if (inv[i] < 0)
            inv[i] += MOD;
        modInv[i] = (modInv[i - 1] * inv[i]) % MOD; // 팩토리얼 곱셈역원 계산
    }

    cin >> n >> m >> k;

    ll ans = Comb(m + n, n);
    for (int i = 0; i < k; i++)
    {
        // cout << ans << '\n';
        int x, y;
        cin >> x >> y;
        bomb.push_back({x, y});
    }
    sort(bomb.begin(), bomb.end(), cmp);

    for (int i = 0; i < k; i++)
    {
        int x = bomb[i].first;
        int y = bomb[i].second;

        ans -= (Comb(x + y, x) * Comb(m - y + n - x, n - x)) % MOD;
        for (int j = 0; j < i; j++)
        {
            int cmp_x = bomb[j].first;
            int cmp_y = bomb[j].second;

            if (cmp_x <= x && cmp_y <= y)
            {
                ans += ((Comb(cmp_x + cmp_y, cmp_x) * Comb(x - cmp_x + y - cmp_y, y - cmp_y)) % MOD) * Comb(m - y + n - x, n - x) % MOD;
                cout << ans << '\n';
            }
        }
        
        while (ans < 0)
            ans += MOD;
    }
    cout << ans % MOD << '\n';
    
    return 0;
}