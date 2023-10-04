#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

int n;
char board[100][100];
bool visited[100][100];
string str;

int add_y[4] = {1, 0, 0, -1};
int add_x[4] = {0, 1, -1, 0};

int cnt;

void bfs(int y_, int x_)
{
    queue<pair <int, int>> q;
    q.push({y_, x_});
    visited[y_][x_] = true;
    char RGB = board[y_][x_];

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_y = y + add_y[i];
            int next_x = x + add_x[i];
            
            if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < n && !visited[next_y][next_x] && board[next_y][next_x] == RGB)
            {
                q.push({next_y, next_x});
                visited[next_y][next_x] = true;
            }
        }
    }
    cnt++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
            board[i][j] = str[j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
                bfs(i, j);
        }
    }
    int ans_1 = cnt;
    cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'R' || board[i][j] == 'G')
                board[i][j] = 'Y';
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
                bfs(i, j);
        }
    }
    int ans_2 = cnt;

    cout << ans_1 << ' ' << ans_2 << '\n';
    
    return 0;
}