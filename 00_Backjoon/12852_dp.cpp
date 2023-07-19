#include <iostream>
using namespace std;

#define MAX 1000010
int n;
int dp[MAX];
int before[MAX];


void Input()
{
    std::cin >> n;
}

void Solution()
{
    dp[1] = 0;
    //경로 표시
    before[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        before[i] = i - 1;

        // 1을 빼준 것보다 더 나은 연산일 때.
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] +  1;
            before[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] +  1;
            before[i] = i / 2;
        }
    }
    std::cout << dp[n] << '\n';
    while (n != 0)
    {
        std::cout << n << ' ';
        n = before[n];
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