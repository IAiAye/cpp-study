#include <iostream>
using namespace std;

int t, n;
int dp[11];

void Input()
{
    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
}

void Solution()
{
    while (t--)
    {
        cin >> n;
        if (dp[n])
        {
            cout << dp[n] << '\n';
            continue;
        }
        for (int i = 4; i <= n; i++)
        {
            // i - 3에 3을 더해주고, i - 2에 2를 더해주고, i - 1에 1을 더해준만큼 존재한다.
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }
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