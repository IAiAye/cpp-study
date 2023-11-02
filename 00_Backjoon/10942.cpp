#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n, m;
int arr[2001];
int dp[2001][2001];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    
}

void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
        if (i != n && arr[i] == arr[i + 1])
            dp[i][i + 1] = 1;
    }
    // 팰린드롬의 길이
    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (dp[j + 1][j + i - 1] == 1 && arr[j] == arr[j + i])
            {
                dp[j][j + i] = 1;
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
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