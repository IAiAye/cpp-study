#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long INF = 16000000;
// A에서 B로 가는 최소 거리
long long d[401][401];
int v, e;

// 연결된 정점과 간선의 가중치
vector <pair <int, int>> graph[20001];

void dijkstra(int start)
{
    d[start][start] = 0;
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
        if (d[start][current] < distance) continue;
        // current에 연결된 간선들을 모두 확인
        for (int i = 0; i < graph[current].size(); i++)
        {
            // current까지의 최소 거리와 간선의 가중치와의 합
            int nextDistance = distance + graph[current][i].first;
            int next = graph[current][i].second;
            // 기존 최소 거리보다 작다면 교체
            if (nextDistance < d[start][next])
            {
                d[start][next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            d[i][j] = INF;
        }
    }
    
    for (int i = 1; i <= e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // a에서 b로 가는 c의 간선 추가
        graph[a].push_back({c, b});
    }
    
    for (int i = 1; i <= v; i++)
    {
        // 모든 지점에서 다익스트라 실행
        dijkstra(i);
    }
    long long ans = 2 * INF;

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            //cout << d[i][j] << ' ';
            // i 에서 출발해 j로 갔다가 i로 다시 돌아오면 사이클 완성
            // 한쪽이라도 연결이 안되있다면 갱신하지 않음
            if (i != j && d[i][j] != INF && d[j][i] != INF) ans = min(d[i][j] + d[j][i], ans);
        }
        //cout << '\n';
    }
    if (ans == 2 * INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}