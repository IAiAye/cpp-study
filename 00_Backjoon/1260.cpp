#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited_dfs[1001];
bool visited_bfs[1001];

// 방문 순서를 기록한다.
int ans_dfs[1001];
int ans_bfs[1001];
int order = 1;

//int arr[100];
// 위와 같은 형태로 vector <int>가 각 배열에 들어가는 형태
// vector <vector <int>> graph(1001)과 같다.
vector <int> graph[1001];
queue <int> q;
int n, m, r;

void dfs(int r)
{
    visited_dfs[r] = true;
    // 방문 순서 기록
    ans_dfs[order++] = r;
    for (auto iter = graph[r].begin(); iter != graph[r].end(); iter++)
    {
        // 방문 안한 지점으로 깊이 우선 탐색
        if (!visited_dfs[*iter]) dfs(*iter);
    }
}

void bfs(int r)
{
    order = 1;

    visited_bfs[r] = true;
    q.push(r);

    // 처음 기록
    ans_bfs[order++] = r;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto iter = graph[u].begin(); iter != graph[u].end(); iter++)
        {
            if (!visited_bfs[*iter])
            {
                // 방문 순서 기록
                ans_bfs[order++] = *iter;

                visited_bfs[*iter] = true;
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
    
    dfs(r);
    bfs(r);
    for (int i = 1; i < order; i++)
    {
        cout << ans_dfs[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i < order; i++)
    {
        cout << ans_bfs[i] << ' ';
    }
    return 0;
}