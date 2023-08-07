#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int n;
#define MAX 300001
ll MOD = 1000000007;
ll arr[MAX];
ll TWO[MAX];

ll sum;

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Solution()
{
    sort(arr, arr + n);
    
    ll temp = 1;
    for (int i = 0; i < n; i++)
    {
        // 2^i - 1
        TWO[i] = temp - 1;
        temp *= 2;
        temp %= MOD;
    }
    
    // 최대값, 최소값을 각각 구해 더하고 빼주기
    ll p = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        p += (TWO[i] * arr[i]) % MOD;
        m += (TWO[(n - 1) - i] * arr[i]) % MOD;
        p %= MOD;
        m %= MOD;
    }
    sum = (p - m + MOD) % MOD;

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