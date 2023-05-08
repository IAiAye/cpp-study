#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int boxes[101][101][101];
int m, n, h;
int cnt, day;

int y_add[6] = {-1, 0, 1, 0, 0, 0};
int x_add[6] = {0, -1, 0, 1, 0, 0};
int z_add[6] = {0, 0, 0, 0, -1, 1};

// i,j, day
queue <pair <tuple <int, int, int>, int>> q;

void bfs()
{
    while(!q.empty())
    {
        int z = get<0> (q.front().first);
        int y = get<1> (q.front().first);
        int x = get<2> (q.front().first);
        day = q.front().second;

        // 안익은 토마토의 수를 cnt라 했을때.
        cnt--;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int z_tmp = z + z_add[i];
            int y_tmp = y + y_add[i];
            int x_tmp = x + x_add[i];

            if ((x_tmp >= 1 && x_tmp <= m) && (y_tmp >= 1 && y_tmp <= n) && (z_tmp >= 1 && z_tmp <= h) && boxes[z_tmp][y_tmp][x_tmp] == 0)
            {
                boxes[z_tmp][y_tmp][x_tmp] = 1;
                q.push({{z_tmp, y_tmp, x_tmp}, day + 1});
                //cout << x_tmp << ' ' << y_tmp << ' ' << z_tmp << ' ' << day + 1 << ' ' << cnt << '\n';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;

    cnt = m * n * h;
    for (int z = 1; z <= h; z++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int x = 1; x <= m; x++)
            {
                // [z][y][x]
                cin >> boxes[z][y][x];
                if (boxes[z][y][x] == 1) 
                {
                    // 0일차에 익어있는 토마토
                    q.push({{z, y, x}, 0});
                }
                // 빈공간은 토마토가 없으므로 빼주기
                else if (boxes[z][y][x] == -1) cnt--;
            }
        }
    }
    
    
    bfs();
    if (cnt == 0) cout << day << '\n';
    else cout << -1 << '\n';
    
    return 0;
}