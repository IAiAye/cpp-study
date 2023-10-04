#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

#define MAX 1005

int n;
ll dp[MAX][MAX];
ll point[MAX];

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> point[i + 1];
}

void Solution()
{
    dp[1][0] = 0;
    dp[1][1] = point[1];
    dp[1][2] = point[1];

    for (int note = 2; note <= n; note++)
    {
        ll maxDP = -1000000001;
        for (int combo = 0; combo <= note; combo++)
        {
            if (combo == 0)
                dp[note][combo] = max(dp[note - 2][note - 1], dp[note - 1][note]);
            else
            {
                dp[note][combo] = dp[note - 1][combo - 1] + combo * point[note];
                maxDP = max(maxDP, dp[note][combo]);
            }
        }
        dp[note][note + 1] = maxDP;
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    ll ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(ans, dp[n][i]);

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