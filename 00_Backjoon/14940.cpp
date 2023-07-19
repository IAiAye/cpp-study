#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int map[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];

int startX, startY;

int add_y[4] = {-1, 0, 0, 1};
int add_x[4] = {0, -1, 1, 0};

// y, x, dis
queue <pair <pair <int, int>, int>> q;

void bfs(int startY, int startX)
{
    visited[startY][startX] = true;
    dist[startY][startX] = 0;

    q.push({{startY, startX}, 0});

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dis = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = y + add_y[i];
            int nextX = x + add_x[i];

            if (!visited[nextY][nextX] && map[nextY][nextX])
            {
                q.push({{nextY, nextX}, dis + 1});
                visited[nextY][nextX] = true;
                dist[nextY][nextX] = dis + 1;
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
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                startY = i;
                startX = j;
            }
        }
    }
}

void Solution()
{
    bfs(startY, startX);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 갈수 있는 땅이지만, 도달할 수 없을 때
            if (map[i][j] == 1 && dist[i][j] == 0) cout << -1 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
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