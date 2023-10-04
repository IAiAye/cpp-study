#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 2001
#define INF 1000000001

int k, n, m;
int a, b;

int d[201][MAX];
vector<vector <int>> graph[MAX];

struct cmp
{
    bool operator()(vector<int>& a, vector<int>& b)
    {
        return a[0] > b[0];
    }
};


void dijkstra(int start)
{
    d[k][start] = 0;
    // 우선순위 큐, 최대 힙을 의미한다.
    // 가중치가 최소가 되는 순대로 정렬. 음수를 이용해 최소 힙을 구현
    priority_queue <vector<int>, vector<vector<int>>, cmp> pq;
    vector<int> tmp = {0, start, k};
    pq.push(tmp);

    while(!pq.empty())
    {
        // 최대 힙에서 거리가 짧은 것이 먼저 올라오게 하기 위해 음수화
        vector<int> cur = pq.top();
        int distance = cur[0];
        int current = cur[1];
        int depth = cur[2];

        pq.pop();

        // 이미 current로 가는 거리가 하나의 간선의 거리보다 짧다면 스킵
        if (d[depth][current] < distance) 
            continue;
        // current에 연결된 간선들을 모두 확인
        int Size = graph[current].size();
        for (int i = 0; i < Size; i++)
        {
            vector<int> ne = graph[current][i];
            
            // current까지의 최소 거리와 간선의 가중치와의 합
            int nextDistance = distance + ne[0];
            int next = ne[1];
            int nextDepth = depth - ne[2];

            // 기존 최소 거리보다 작다면 교체
            if (nextDepth > 0 && nextDistance < d[nextDepth][next])
            {
                d[nextDepth][next] = nextDistance;
                vector<int> temp = {nextDistance, next, nextDepth};
                pq.push(temp);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> k >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w, h;
        cin >> u >> v >> w >> h;
        vector<int> tmp1 = {w, v, h};
        vector<int> tmp2 = {w, u, h};
        graph[u].push_back(tmp1);
        graph[v].push_back(tmp2);
    }
    cin >> a >> b;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
            d[i][j] = INF;
    }
    
    dijkstra(a);

    int ans = INF;

    for (int i = 1; i <= k; i++)
        ans = min(d[i][b], ans);
    

    if (ans != INF)
        cout << ans << '\n';
    else
        cout << -1 << '\n';
    return 0;
}
