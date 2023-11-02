#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
using ll = long long;

int n, m, ans;
char board[1001][1001];
int visited[1001][1001];

void dfs(int y, int x)
{
    // 방문했으나, 탐색 중
    visited[y][x] = 1;
    int nextY;
    int nextX;

    switch (board[y][x])
    {
    case 'U':
        nextY = y - 1;
        nextX = x;
        break;
    case 'D':
        nextY = y + 1;
        nextX = x;
        break;
    case 'R':
        nextY = y;
        nextX = x + 1;
        break;
    case 'L':
        nextY = y;
        nextX = x - 1;
        break;
    
    default:
        break;
    }
    if (visited[nextY][nextX] == 0)
        dfs(nextY, nextX);
    // 루프를 발견
    else if (visited[nextY][nextX] == 1)
        ans++;

    // 탐색 종료
    visited[y][x] = 2;
}

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            board[i][j] = str[j - 1];
        }
    }
}

void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j])
                dfs(i, j);
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