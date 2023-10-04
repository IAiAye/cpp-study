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
int cheese[101][101];
int cntVisit[101][101];
bool visited[101][101];
int cnt;

int add_y[4] = {1, 0, -1, 0};
int add_x[4] = {0, 1, 0, -1};

void dfs(int y, int x)
{

    for (int i = 0; i < 4; i++)
    {
        int nexty = y + add_y[i];
        int nextx = x + add_x[i];

        if (1 <= nexty && nexty <= n && 1 <= nextx && nextx <= m && !visited[nexty][nextx])
        {
            if (cheese[nexty][nextx] == 0)
            {
                visited[nexty][nextx] = true;
                dfs(nexty, nextx);
            }
            else
            {
                cntVisit[nexty][nextx]++;
                if (cntVisit[nexty][nextx] == 2)
                {
                    visited[nexty][nextx] = true;
                    cheese[nexty][nextx] = 0;
                    cnt--;
                }
            }
        }
    }
}

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> cheese[i][j];
            if (cheese[i][j] == 1)
                cnt++;
        }
    }
}

void Solution()
{
    int ans = 0;
    while(cnt)
    {
        ans++;
        dfs(1, 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                visited[i][j] = false;
                cntVisit[i][j] = 0;
            }
        }
        // cout << cnt << '\n';
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