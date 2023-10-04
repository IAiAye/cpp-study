#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int r, c;
bool isPass[26];
char board[21][21];
int MAX;
int addX[4] = {1, 0, -1, 0};
int addY[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt)
{
    MAX = max(MAX, cnt);

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + addY[i];
        int nextX = x + addX[i];

        if (1 <= nextY && nextY <= r && 1 <= nextX && nextX <= c)
        {
            if (!isPass[board[nextY][nextX] - 'A'])
            {
                isPass[board[nextY][nextX] - 'A'] = true;
                dfs(nextY, nextX, cnt + 1);
                isPass[board[nextY][nextX] - 'A'] = false;
            }
        }
    }
    
}

void Input()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> board[i][j];
        }
    }
}

void Solution()
{
    isPass[board[1][1] - 'A'] = true;
    dfs(1, 1, 1);

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