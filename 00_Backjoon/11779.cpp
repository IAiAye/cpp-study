#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int Start, End;

int INF = 200000000;

// before[A] = B 이면 A이전에 B가 있던 것이다.
int before[1001];
int dist[1001];
// 벡터 내부에는 가는 도시와 가중치, 배열의 인덱스는 출발 도시
vector <pair <int, int>> graph[1001];
// 최대힙으로 되어있다.
priority_queue <pair <int, int>> pq;

void dijkstra(int start)
{
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        // 짧은 것이 먼저 오도록 음수화한다.
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        // 가지 쳐내기를 통해 시간 절약
        if (distance > dist[current]) continue;

        for (int i = 0; i < graph[current].size(); i++)
        {
            int nextDist = distance + graph[current][i].second;
            int next = graph[current][i].first;

            if (nextDist < dist[next])
            {
                dist[next] = nextDist;
                before[next] = current;
                pq.push({-nextDist, next});
            }
        }
    }
}

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int departure, arrive, cost;
        cin >> departure >> arrive >> cost;
        graph[departure].push_back({arrive, cost});
    }
    cin >> Start >> End;
}

void Solution()
{    
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    
    dijkstra(Start);

    cout << dist[End] << '\n';
    vector <int> path;

    int temp = End;

    while (temp)
    {
        path.push_back(temp);
        temp = before[temp];
    }

    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << ' ';
    }
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
    
    return 0;
}