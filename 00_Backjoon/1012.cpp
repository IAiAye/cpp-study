#include <iostream>
using namespace std;

// int map[n][m];
int map[50][50];

int t, m, n, k;

void dfs(int i, int j)
{
    // visited를 대신한다. 1이 아니라면 방문한 것
    map[i][j] = 2;

    if (i > 0 && map[i - 1][j] == 1) dfs(i - 1, j);
    if (j > 0 && map[i][j - 1] == 1) dfs(i, j - 1);
    if (i < n - 1 && map[i + 1][j] == 1) dfs(i + 1, j);
    if (j < m - 1 && map[i][j + 1] == 1) dfs(i, j + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin >> t;
    while(t--)
    {
        cin >> m >> n >> k;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                //초기화
                map[i][j] = 0;
            }
        }
        
        int cnt = 0;
        while(k--)
        {
            int x, y;
            cin >> x >> y;
            // 배추 심기
            map[y][x] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 1)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}