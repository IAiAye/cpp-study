#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

int n;
char board[2000][2000];
bool visited[2000][2000];
int fy, fx;
int cnt;

// 아래로 못간다고 생각
int dy[7] = {1, 1, 0, 0, -1, -1, -1};
int dx[7] = {-1, 1, -1, 1, -1, 0, 1};

void dfs(int y, int x)
{
    visited[y][x] = true;
    cnt++;

    for (int i = 0; i < 7; i++)
    {
        int nexty = y + dy[i];
        int nextx = x + dx[i];

        if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < n && !visited[nexty][nextx] && board[nexty][nextx] == '.')
            dfs(nexty, nextx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'F')
            {
                fy = i;
                fx = j;
            }
        }
    }
    
    dfs(fy, fx);
    cout << cnt - 1 << '\n';
    
    return 0;
}