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

#define MAX 500001

int n;
// R G B
int dp[MAX][3];
int color[MAX][3];
vector<int> graph[MAX];
bool visited[MAX];
vector<char> str;

char RGB(int k)
{
    switch (k)
    {
    case 0:
        return 'R';
    case 1:
        return 'G';
    case 2:
        return 'B';
    }
    return '1';
}

int dfs_max(int n, int pre, int k)
{
    if (dp[n][k])
        return dp[n][k];

    // visited[n] = true;

    int Size = graph[n].size();
    for (int i = 0; i < Size; i++)
    {
        int next = graph[n][i];
        if (next != pre)
        {
            int a = dfs_max(next, n, (k + 1) % 3);
            int b = dfs_max(next, n, (k + 2) % 3);
            dp[n][k] += max(a, b);
        }
    }
    return dp[n][k] += color[n][k];
}

void dfs_str(int n, int k)
{
    str[n - 1] = RGB(k);

    visited[n] = true;

    int Size = graph[n].size();
    for (int i = 0; i < Size; i++)
    {
        int next = graph[n][i];
        if (!visited[next])
        {
            int a = dp[next][(k + 1) % 3];
            int b = dp[next][(k + 2) % 3];
            if (a > b)
                dfs_str(next, (k + 1) % 3);
            else
                dfs_str(next, (k + 2) % 3);
        }
    }
}

void Input()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        cin >> color[i][0] >> color[i][1] >> color[i][2];
}

void Solution()
{
    int ans = 0;
    int idx = -1;
    for (int i = 0; i < 3; i++)
    {
        if (ans < dfs_max(1, -1, i))
        {
            ans = dp[1][i];
            idx = i;
        }
    }
    
    str.resize(n);
    dfs_str(1, idx);

    cout << ans << '\n';
    for (auto ch : str)
        cout << ch;
    cout << '\n';
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