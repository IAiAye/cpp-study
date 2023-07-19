#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100001

bool visited[MAX];
int route[MAX];
int n, k;
// 위치, 시간
queue <pair <int, int>> q;
vector <int> path;

void bfs()
{
    q.push({n, 0});
    visited[n] = true;

    while (!q.empty())
    {
        int pos = q.front().first;
        int time = q.front().second;

        q.pop();
        
        if (pos == k)
        {
            cout << time << '\n';
            path.resize(time + 1);
            
            for (int i = time; i >= 0 ; i--)
            {
                path[i] = pos;
                pos = route[pos];
            }
            for (int i = 0; i < time + 1; i++)
            {
                cout << path[i] << ' ';
            }
            return;
        }
        
        if (pos - 1 >= 0 && !visited[pos - 1]) 
        {
            q.push({pos - 1, time + 1});
            visited[pos - 1] = true;
            route[pos - 1] = pos;
        }
        if (pos + 1 < MAX && !visited[pos + 1] && pos < k) 
        {
            q.push({pos + 1, time + 1});
            visited[pos + 1] = true;
            route[pos + 1] = pos;
        }
        if (pos * 2 < MAX && !visited[pos * 2] && pos < k) 
        {
            q.push({pos * 2, time + 1});
            visited[pos * 2] = true;
            route[pos * 2] = pos;
        }
    }
}

void Input()
{
    cin >> n >> k;
}

void Solution()
{
    bfs();
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}