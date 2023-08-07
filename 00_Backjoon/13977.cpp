#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define MAX 4000001
long long MOD = 1000000007;
int m;
long long n, k;

long long fact[MAX];
long long factInv[MAX];
long long inv[MAX];

void Input()
{
    cin >> m;
}

void Solution()
{
    fact[0] = factInv[0] = 1;
    fact[1] = inv[1] = factInv[1] = 1;
    for (long long i = 2; i < MAX; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = (MOD - (MOD / i)) * inv[MOD % i] % MOD; // i^-1 = -q * r^-1
        factInv[i] = factInv[i - 1] * inv[i] % MOD;
    }
    while (m--)
    {
        cin >> n >> k;
        cout << (fact[n] * factInv[k]) % MOD * factInv[n - k] % MOD << '\n';
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