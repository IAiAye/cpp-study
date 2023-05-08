#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[100001];

// 방문 순서를 기록한다.
int ans[100001];
int order = 1;

//int arr[100];
// 위와 같은 형태로 vector <int>가 각 배열에 들어가는 형태
// vector <vector <int>> graph(100001)과 같다.
vector <int> graph[100001];
queue <int> q;
int n, m, r;

void bfs(int r)
{
    visited[r] = true;
    q.push(r);

    // 처음 기록
    ans[r] = order++;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto iter = graph[u].begin(); iter != graph[u].end(); iter++)
        {
            if (!visited[*iter])
            {
                // 방문 순서 기록
                ans[*iter] = order++;

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
    
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        // 오름차 순으로 정렬
        sort(graph[i].begin(), graph[i].end());
    }
    
    bfs(r);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
    
    return 0;
}