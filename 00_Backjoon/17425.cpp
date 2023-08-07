#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int Test;
int MAX = 1000000;
long long dp[1000001];

void Input()
{
    cin >> Test;
}

void Solution()
{
    // 모든 수의 약수 1 깔아주기
    for (int i = 1; i <= MAX; i++)
        dp[i] = 1;
    
    for (int i = 2; i <= MAX; i++)
    {
        for (int j = 1; i * j <= MAX; j++)
            dp[i * j] += i;
    }
    // 누적합
    for (int i = 1; i <= MAX; i++)
        dp[i] += dp[i - 1];
    
    while (Test--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
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