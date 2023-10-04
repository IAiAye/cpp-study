#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

#define MAX 1001

int n;
int dp[MAX][3][3];
int cost[MAX][3];

int dfs(int num, int k, int start)
{
    // cout << num << ' ' << k << ' ' << start << '\n';
    if (dp[num][k][start])
        return dp[num][k][start];

    if (num == n)
    {
        if (k == start)
            return dp[num][k][start] = 1000001;
        
        return dp[num][k][start] = cost[num][k];
    }
    
    int a = dfs(num + 1, (k + 1) % 3, start) + cost[num][k];
    int b = dfs(num + 1, (k + 2) % 3, start) + cost[num][k];

    return dp[num][k][start] = min(a, b);
}

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
}

void Solution()
{
    int ans = 1000000000;
    for (int i = 0; i < 3; i++)
    {
        dfs(1, i, i);
        ans = min(ans, dp[1][i][i]);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
    // }
    
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