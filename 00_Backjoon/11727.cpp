#include <iostream>
using namespace std;

int n;
int dp[1001];

void Input()
{
    cin >> n;
}

void Solution()
{
    dp[1] = 1;
    dp[2] = 3;

    // if (n == 1) cout << 1 << '\n';
    // if (n == 2) cout << 2 << '\n';

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] % 10007 + (dp[i - 2] * 2) % 10007) % 10007;
    }
    cout << dp[n] << '\n';
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