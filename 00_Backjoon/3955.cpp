#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
ll t;
ll k, c;

ll gcd(ll a, ll b)
{
    ll temp;
    while (b > 0)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}

// a의 역원을 구한다. (mod b)
ll EEu(ll a, ll b)
{
    ll r0 = a, r1 = b;
    ll x0 = 1, x1 = 0;
    ll y0 = 0, y1 = 1;
    ll q;
    
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
    cin >> t;
}

void Solution()
{
    while (t--)
    {
        cin >> k >> c;
        if (k == 1 && c == 1)
        {
            cout << 2 << '\n';
            continue;
        }
        
        if (gcd(k, c) != 1)
        {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        ll cInv = EEu(c, k);
        while (c * cInv <= k)
            cInv += k;
        if (cInv > 1e9)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << cInv << '\n';

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