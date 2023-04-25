#include <iostream>
#include <algorithm>
using namespace std;

int heights[501][501];
// 목표 좌표까지 도달할 수 있는 경우의 수
int dp[501][501];
// w : 가로, h : 세로
int w, h;

// 상 하 좌 우 탐색
int x_add[4] = {0, 0, -1, 1};
int y_add[4] = {-1, 1, 0, 0};

// 모든 경로를 깊이 탐색한다.
int dfs(int y, int x)
{
    // 종점이라면 1 반환
    if (x == w && y == h) return 1;
    // 이미 값이 있다면 그 값 반환
    if (dp[y][x] >= 0) return dp[y][x];

    dp[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + x_add[i];
        int next_y = y + y_add[i];

        if (next_x >= 1 && next_x <= w && next_y >= 1 && next_y <= h)
        {
            // y, x에서 다음 좌표로 내려갈수 있다면
            if (heights[y][x] > heights[next_y][next_x])
            {
                dp[y][x] += dfs(next_y, next_x);
            }
        }
    }
    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> h >> w;

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> heights[i][j];
            dp[i][j] = -1;
        }
    }
    // for (int i = 1; i <= h; i++)
    // {
    //     for (int j = 1; j <= w; j++)
    //     {
    //         cout << dfs(i, j) << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dfs(1, 1) << '\n';

    return 0;
}