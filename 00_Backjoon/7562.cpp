#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool visited[300][300];
int t, n, cnt;
int x, y, target_x, target_y;

int x_add[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int y_add[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

// x, y, cnt
queue <pair < pair <int,int>, int>> q;

void bfs()
{
    visited[x][y] = true;
    q.push({{x,y}, 0});

    while(!q.empty())
    {
        int x_ = q.front().first.first;
        int y_ = q.front().first.second;
        int cnt = q.front().second;

        if (x_ == target_x && y_ == target_y)
        {
            cout << cnt << '\n';
            cnt = 0;
            // 큐 비워주기
            while(!q.empty()) q.pop();
            break;
        }
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x_tmp = x_ + x_add[i];
            int y_tmp = y_ + y_add[i];
            if ((x_tmp >= 0 && x_tmp < n) && (y_tmp >= 0 && y_tmp < n) && !visited[x_tmp][y_tmp])
            {
                visited[x_tmp][y_tmp] = true;
                q.push({{x_tmp, y_tmp}, cnt + 1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--)
    {
        cin >> n;
        // 초기화
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        }

        cin >> x >> y >> target_x >> target_y;
        bfs();
    }

    return 0;
}