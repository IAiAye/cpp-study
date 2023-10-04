#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n;
int board[17][17];
int cnt;

// dir 0 가로, 1 세로, 2 대각
void dfs(int y, int x, int dir)
{
    if (y == n && x == n)
    {
        cnt++;
        return;
    }

    bool isRight = x + 1 <= n && board[y][x + 1] == 0;
    bool isDown = y + 1 <= n && board[y + 1][x] == 0;

    if (dir == 0 && isRight)
    {
        dfs(y, x + 1, 0);
        if (isDown && board[y + 1][x + 1] == 0)
            dfs(y + 1, x + 1, 2);
    }
    else if (dir == 1 && isDown)
    {
        dfs(y + 1, x, 1);
        if (isRight && board[y + 1][x + 1] == 0)
            dfs(y + 1, x + 1, 2);
    }
    else if (dir == 2)
    {
        if (isRight)
            dfs(y, x + 1, 0);
        if (isDown)
            dfs(y + 1, x, 1);
        if (isRight && isDown && board[y + 1][x + 1] == 0)
            dfs(y + 1, x + 1, 2);
    }
}

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }   
    }
}

void Solution()
{
    dfs(1, 2, 0);
    cout << cnt << '\n';
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