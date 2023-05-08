#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[101];

// 1번 컴퓨터 제외
int ans = 0;

//int arr[100];
// 위와 같은 형태로 vector <int>가 각 배열에 들어가는 형태
// vector <vector <int>> graph(100001)과 같다.
vector <int> graph[101];
queue <int> q;
int n, m;

void bfs(int r)
{
    visited[r] = true;
    q.push(r);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto iter = graph[u].begin(); iter != graph[u].end(); iter++)
        {
            if (!visited[*iter])
            {
                ans++;

                visited[*iter] = true;
                q.push(*iter);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    bfs(1);
    cout << ans;
    
    return 0;
}