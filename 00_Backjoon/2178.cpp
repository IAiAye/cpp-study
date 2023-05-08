#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

// int map[n][m];
int map[100][100];

int m, n;

// y, x, cnt
queue <pair < pair <int, int> , int > > q;

int y_add[4] = {-1, 0, 1, 0};
int x_add[4] = {0, -1, 0, 1};

void bfs(int i, int j)
{
    // 1 방지
    map[i][j] = 2;
    q.push({{i, j}, 1});

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second + 1;

        // 미로의 끝에 도달했을 경우
        if ((y == n - 1) && (x == m - 1))
        {
            cout << cnt - 1 << '\n';
            break;
        }

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            // 기존 지도에서 나가지 않는지 체크
            if ((y + y_add[i] >= 0 && x + x_add[i] >= 0) && (y + y_add[i] < n && x + x_add[i] < m))
            {
                if (map[y + y_add[i]][x + x_add[i]] == 1) 
                {
                    map[y + y_add[i]][x + x_add[i]] = cnt; 
                    q.push({{y + y_add[i], x + x_add[i]}, cnt});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }
    bfs(0, 0);

    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}