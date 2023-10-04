#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
using namespace std;

int tc;
int n;  
int MAX;


void Input()
{
    cin >> tc;
}

void Solution()
{
    while (tc--)
    {
        MAX = -1;
        cin >> n;
        vector<pair<int, int>> v(n, {0, 0});
        for (int i = 0; i < n; i++)
            cin >> v[i].first;
        for (int i = 0; i < n; i++)
            cin >> v[i].second;
        
        vector<vector<int>> dp(n, {0, 0, 0});
        dp[0][0] = 0;
        dp[0][1] = v[0].first;
        dp[0][2] = v[0].second;

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + v[i].first;
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + v[i].second;
        }
        MAX = max(dp[n - 1][1], dp[n - 1][2]);
        MAX = max(dp[n - 1][0], MAX);
        cout << MAX << '\n';
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