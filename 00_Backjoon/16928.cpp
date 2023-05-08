#include <iostream>
#include <queue>
#include <utility>
#include <map>
using namespace std;

int n, m;
bool visited[101];
queue <pair <int, int>> q;
map <int, int> ladder;
map <int, int> snake;

void bfs()
{
    visited[1] = true;
    q.push({1, 0});
    while(!q.empty())
    {
        int pos = q.front().first;
        int cnt = q.front().second + 1;

        // 목표지점 도달시 종료
        if (pos == 100)
        {
            cout << cnt - 1 << '\n';
            return;
        }

        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            // 100을 넘으면 안되고 방문했는지도 체크
            if (pos + i <= 100 && !visited[pos + i])
            {
                visited[pos + i] = true;
                if (ladder.find(pos + i) != ladder.end())
                {
                    // 사다리 타고 올라간 곳도 체크
                    visited[ladder[pos + i]] = true;
                    q.push({ladder[pos + i], cnt});
                }
                // 1 - 50, 55 - 45, 47 - 99 와 같은 경우도 있을 수 있기때문에 뱀도 고려
                else if (snake.find(pos + i) != snake.end())
                {
                    visited[snake[pos + i]] = true;
                    q.push({snake[pos + i], cnt});
                }
                else q.push({pos + i, cnt});
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
        int a, b;
        cin >> a >> b;
        ladder.insert({a, b});
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        snake.insert({a, b});
    }
    bfs();

    return 0;
}