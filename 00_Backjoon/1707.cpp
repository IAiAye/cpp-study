#include <iostream>
#include <vector>
using namespace std;

int k;
int v, e;
bool flag;
vector <int> graph[20001];
// 이분 그래프는 모든 간선의 양 정점이 다른 색깔이면 이분그래프라 할 수 있다.
// -1 : blue, 1 : red;
int colors[20001];

// 시작 정점 r
void dfs(int r, int color)
{
    colors[r] = color;
    for (auto iter = graph[r].begin(); iter != graph[r].end(); iter++)
    {
        // 미방문일때,
        if (colors[*iter] == 0) dfs(*iter, (-1) * color);
        // 같은 색깔의 노드를 발견했을때
        else if (colors[*iter] == color) 
        {
            flag = false;
            return;
        }
        // 다른 경우 dfs 종료
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    while(k--)
    {
        cin >> v >> e;
        // 그래프, 컬러 초기화
        for (int i = 1; i <= v; i++)
        {
            vector <int>().swap(graph[i]);
            colors[i] = 0;
        }
        flag = true;
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // 끊어져 있을수도 있으므로 깊이 우선 탐색 후 방문기록이 없다면 또 다시 탐색.
        for (int i = 1; i <= v; i++)
        {
            if (!colors[i]) dfs(i, -1);
        }
        
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}