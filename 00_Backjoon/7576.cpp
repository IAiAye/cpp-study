#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int boxes[1001][1001];
int m, n;
int cnt, day;

int y_add[4] = {-1, 0, 1, 0};
int x_add[4] = {0, -1, 0, 1};

// i,j, day
queue <pair <pair <int, int>, int>> q;

void bfs()
{
    while(!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        day = q.front().second;

        // 안익은 토마토의 수를 cnt라 했을때.
        cnt--;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int y_tmp = y + y_add[i];
            int x_tmp = x + x_add[i];

            if ((x_tmp >= 1 && x_tmp <= m) && (y_tmp >= 1 && y_tmp <= n) && boxes[y_tmp][x_tmp] == 0)
            {
                boxes[y_tmp][x_tmp] = 1;
                q.push({{y_tmp, x_tmp}, day + 1});
                //cout << x_tmp << ' ' << y_tmp << ' ' << day + 1 << '\n';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    cnt = m * n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> boxes[i][j];
            if (boxes[i][j] == 1) 
            {
                // 0일차에 익어있는 토마토
                q.push({{i, j}, 0});
            }
            // 빈공간은 토마토가 없으므로 빼주기
            else if (boxes[i][j] == -1) cnt--;
        }
    }
    
    bfs();
    if (cnt == 0) cout << day << '\n';
    else cout << -1 << '\n';
    
    return 0;
}