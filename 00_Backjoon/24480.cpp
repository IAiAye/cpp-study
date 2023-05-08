#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100001];

// 방문 순서를 기록한다.
int ans[100001];
int order = 1;

//int arr[100];
// 위와 같은 형태로 vector <int>가 각 배열에 들어가는 형태
// vector <vector <int>> graph(100001)과 같다.
vector <int> graph[100001];

void dfs(int r)
{
    visited[r] = true;
    // 방문 순서 기록
    ans[r] = order++;
    for (auto iter = graph[r].begin(); iter != graph[r].end(); iter++)
    {
        // 방문 안한 지점으로 깊이 우선 탐색
        if (!visited[*iter]) dfs(*iter);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, r;
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
        // 내림차 순으로 정렬
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }
    
    dfs(r);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
    
    return 0;
}