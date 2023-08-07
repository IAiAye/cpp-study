#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

using ll = long long;
ll n, m;
const ll MOD = 1000000007;
using matrix = vector<vector<ll>>;

matrix operator*(matrix &a, matrix &b)
{
    ll x = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    ll y = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    ll z = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    ll w = a[1][0] * b[0][1] + a[1][1] * b[1][1];
 
    x %= MOD;
    y %= MOD;
    z %= MOD;
    w %= MOD;
 
    matrix ret = { { x,y },{ z,w } };
    return ret;
}
void power(matrix &F, ll n)
{
    if (n <= 1) 
        return;
 
    matrix E = { { 1, 1 },{ 1, 0 } };
    power(F, n / 2);
    F = F * F;
    if (n % 2 != 0) {
        F = F * E;
    }
}

ll fib(ll n)
{
    matrix F = { { 1, 1 },{ 1, 0 } };
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

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

void Input()
{
    cin >> n >> m;
}

void Solution()
{
    ll GCD = gcd(n, m);
    cout << fib(GCD) << '\n';
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