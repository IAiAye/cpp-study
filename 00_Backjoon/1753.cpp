#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int INF = 3000000;
int v, e;
int k;

// 연결된 정점과 간선의 가중치
vector <pair <int, int>> graph[20001];
// 시작 정점에서 가는데 걸리는 최소 가중치
int d[20001];

void dijkstra(int start)
{
    d[start] = 0;
    // 우선순위 큐, 최대 힙을 의미한다.
    // 가중치가 최소가 되는 순대로 정렬. 음수를 이용해 최소 힙을 구현
    priority_queue <pair <int, int>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        // 최대 힙에서 거리가 짧은 것이 먼저 올라오게 하기 위해 음수화
        int distance = -pq.top().first;
        int current = pq.top().second;
        //cout << distance << ' ' << current << '\n';
        pq.pop();

        // 이미 current로 가는 거리가 하나의 간선의 거리보다 짧다면 스킵
        if (d[current] < distance) continue;
        // current에 연결된 간선들을 모두 확인
        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            // current까지의 최소 거리와 간선의 가중치와의 합
            int nextDistance = distance + graph[current][i].second;
            // 기존 최소 거리보다 작다면 교체
            if (nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e >> k;
    for (int i = 1; i <= v; i++)
    {
        d[i] = INF;
    }
    
    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // u에서 v로 가는 w의 간선 추가
        graph[u].push_back({v, w});
    }
    
    dijkstra(k);
    for (int i = 1; i <= v; i++)
    {
        if (d[i] != INF) cout << d[i] << '\n';
        else cout << "INF" << '\n';
    }
    return 0;
}