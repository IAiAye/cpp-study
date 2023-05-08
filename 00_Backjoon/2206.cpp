#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int n, m;
// 벽을 안뚫었을때의 방문
bool visited_0[1001][1001];
// 벽을 뚫었을때의 방문
bool visited_1[1001][1001];

int y_add[4] = {-1, 0, 1, 0};
int x_add[4] = {0, -1, 0, 1};

bool map[1001][1001];
int ans = -1;

//좌표 두개, 이동 휫수, 벽을 뚫었는지
queue <pair <pair <int, int>, pair <int, bool>>> q;

void bfs()
{
    visited_0[1][1] = true;
    q.push({{1, 1}, {1, false}});

    while(!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second.first + 1;
        bool isPen = q.front().second.second;

        //cout << x << ' ' << y << ' ' << cnt - 1 << ' ' << isPen << '\n';

        if (y == n && x == m)
        {
            ans = cnt - 1;
            return;
        }

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int y_tmp = y + y_add[i];
            int x_tmp = x + x_add[i];
            // 범위 확인
            if ((y_tmp >= 1 && y_tmp <= n) && (x_tmp >= 1 && x_tmp <= m))
            {
                // 다음 위치가 0일때
                if (!map[y_tmp][x_tmp])
                {
                    // 이전 경로에서 한번도 뚫지않았고, 이번에도 안뚫어도 될때
                    if (!visited_0[y_tmp][x_tmp] && !isPen)
                    {
                        visited_0[y_tmp][x_tmp] = true;
                        // 안뚫고도 그 지점에 먼저 도달한다면 더 이상적이다.
                        visited_1[y_tmp][x_tmp] = true;
                        q.push({{y_tmp, x_tmp},{cnt, isPen}});
                    }
                    // 이전 경로에서 뚫었었다면,
                    if (!visited_1[y_tmp][x_tmp] && isPen)
                    {
                        visited_1[y_tmp][x_tmp] = true;
                        q.push({{y_tmp, x_tmp},{cnt, isPen}});
                    }
                }
                // 다음위치가 1일때
                else
                {
                    int y_tmp_pen = y_tmp + y_add[i];
                    int x_tmp_pen = x_tmp + x_add[i];
                    if ((y_tmp_pen >= 1 && y_tmp_pen <= n) && (x_tmp_pen >= 1 && x_tmp_pen <= m))
                    {
                        // 다음 위치가 0일때
                        if (!map[y_tmp_pen][x_tmp_pen])
                        {
                            // 이전 경로에서 한번도 뚫지않았고, 이번에 뚫어야 할때
                            // 한번이라도 뚫었었다면 못뚫는다.
                            if (!visited_1[y_tmp_pen][x_tmp_pen] && !isPen)
                            {
                                visited_1[y_tmp_pen][x_tmp_pen] = true;
                                // 부술때 카운트 하나 더 추가
                                q.push({{y_tmp_pen, x_tmp_pen},{cnt + 1, !isPen}});
                            }
                        }
                    }
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
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            map[i][j] = s[j - 1] - '0';
        }
    }
    bfs();
    cout << ans << '\n';

    return 0;
}