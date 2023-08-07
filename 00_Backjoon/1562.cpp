#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;

#define MOD 1000000000
int n;
int dp[101][10][1 << 10];

// digit은 자리수, Num은 그 자리의 숫자, bit는 0~9가 쓰였는지 체크하는 비트마스킹
int dfs(int digit, int num, int bit)
{
    if (dp[digit][num][bit])
        return dp[digit][num][bit];
    if (digit == n)
    {
        if (bit == (1 << 10) - 1)
            return dp[digit][num][bit] = 1;
        else
            return dp[digit][num][bit] = 0;
    }
    int result = 0;

    if (num + 1 < 10)
        result += dfs(digit + 1, num + 1, bit | 1 << (num + 1));
    if (num - 1 >= 0)
        result += dfs(digit + 1, num - 1, bit | 1 << (num - 1));
    
    return dp[digit][num][bit] = (result % MOD);
}

void Input()
{
    cin >> n;
}

void Solution()
{
    int ans = 0;

    // 1~9에서 시작하는 계단수 확인
    for (int i = 1; i < 10; i++)
    {
        ans += dfs(1, i, 1 << i);
        ans %= MOD;
    }
    cout << ans << '\n';
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