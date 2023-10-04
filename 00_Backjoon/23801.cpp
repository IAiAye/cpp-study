#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 100001
#define INF 300000000001

int n, m;
int x, z;
int p;

vector<ll> dX(MAX, INF);
vector<ll> dZ(MAX, INF);
vector<pair <ll, int>> graph[MAX];
vector<int> middle;

void dijkstra(int start, vector<ll>& d)
{
    d[start] = 0;
    // 우선순위 큐, 최대 힙을 의미한다.
    // 가중치가 최소가 되는 순대로 정렬. 음수를 이용해 최소 힙을 구현
    priority_queue <pair <ll, int>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        // 최대 힙에서 거리가 짧은 것이 먼저 올라오게 하기 위해 음수화
        ll distance = -pq.top().first;
        int current = pq.top().second;

        pq.pop();

        // 이미 current로 가는 거리가 하나의 간선의 거리보다 짧다면 스킵
        if (d[current] < distance) 
            continue;
        // current에 연결된 간선들을 모두 확인
        int Size = graph[current].size();
        for (int i = 0; i < Size; i++)
        {
            // current까지의 최소 거리와 간선의 가중치와의 합
            ll nextDistance = distance + graph[current][i].first;
            int next = graph[current][i].second;

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
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    cin >> x >> z;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int tmp;
        cin >> tmp;
        middle.push_back(tmp);
    }
    
    dijkstra(x, dX);
    dijkstra(z, dZ);

    ll ans = INF * 2;

    for (auto& mid : middle)
    {
        if (dX[mid] != INF && dZ[mid] != INF)
            ans = min(ans, dX[mid] + dZ[mid]);
    }
    
    if (ans == INF * 2)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}
