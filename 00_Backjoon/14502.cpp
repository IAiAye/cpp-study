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
int board[8][8];
int cnt;
vector<pair <int, int>> virus;

int add_y[4] = {1, 0, -1, 0};
int add_x[4] = {0, 1, 0, -1};

int bfs(int c)
{
    queue<pair <int, int>> q;
    for (auto v : virus)
        q.push(v);
    vector<bool> tmp2(8, false);
    vector<vector<bool>> visited(8, tmp2);

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nexty = y + add_y[i];
            int nextx = x + add_x[i];

            if (0 <= nexty && nexty < n && 0 <= nextx && nextx < m)
            {
                if (board[nexty][nextx] == 0 && !visited[nexty][nextx])
                {
                    visited[nexty][nextx] = true;
                    c--;
                    q.push({nexty, nextx});
                }
            }
        }
    }
    return c;
}

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back({i, j});
            else if (board[i][j] == 0)
                cnt++;
        }
    }
}

void Solution()
{
    int ans = 0;
    int area = n * m;
    for (int i = 0; i < area - 2; i++)
    {
        if (board[i / m][i % m] != 0)
            continue;
        
        for (int j = i + 1; j < area - 1; j++)
        {
            if (board[j / m][j % m] != 0)
                continue;

            for (int k = j + 1; k < area; k++)
            {
                if (board[k / m][k % m] != 0)
                    continue;

                board[i / m][i % m] = 1;
                board[j / m][j % m] = 1;
                board[k / m][k % m] = 1;

                ans = max(ans, bfs(cnt - 3));

                board[i / m][i % m] = 0;
                board[j / m][j % m] = 0;
                board[k / m][k % m] = 0;
            }
            
        }
        
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