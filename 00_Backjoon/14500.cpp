#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

int n, m;
int numbers[501][501];
bool visited[501][501];
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};
int MAX = -1;

void dfs(int y, int x, int depth, int sum)
{
    if (depth == 4)
    {
        MAX = max(MAX, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];
        if (nextY >= 1 && nextY <= n && nextX >= 1 && nextX <= m)
        {
            if (!visited[nextY][nextX])
            {
                visited[nextY][nextX] = true;
                dfs(nextY, nextX, depth + 1, sum + numbers[nextY][nextX]);
                visited[nextY][nextX] = false;
            }
        }
    }

    // ㅓ shape
    if (y - 1 >= 1 && x - 1 >= 1 && y + 1 <= n)
        MAX = max(MAX, numbers[y - 1][x] + numbers[y][x] + numbers[y + 1][x] + numbers[y][x - 1]);
    // ㅏ shape
    if (y - 1 >= 1 && x + 1 <= m && y + 1 <= n)
        MAX = max(MAX, numbers[y - 1][x] + numbers[y][x] + numbers[y + 1][x] + numbers[y][x + 1]);
    // ㅗ shape
    if (y - 1 >= 1 && x - 1 >= 1 && x + 1 <= m)
        MAX = max(MAX, numbers[y - 1][x] + numbers[y][x] + numbers[y][x + 1] + numbers[y][x - 1]);
    // ㅜ shape
    if (y + 1 <= n && x - 1 >= 1 && x + 1 <= m)
        MAX = max(MAX, numbers[y + 1][x] + numbers[y][x] + numbers[y][x + 1] + numbers[y][x - 1]);
    
}

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> numbers[i][j];
        }
    }
}

void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            visited[i][j] = true;
            dfs(i, j, 1, numbers[i][j]);
            visited[i][j] = false;
        }
    }

    cout << MAX << '\n';
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