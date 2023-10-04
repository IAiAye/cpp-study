#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
using namespace std;

int n, m, x;
int MAX = -1;

#define INF 1000001
vector<pair <int,int>> graph[2][1001];
bool visited[1001];

vector<int> dijkstra(int op)
{
    vector<int> d(n + 1, INF);
    d[x] = 0;

    priority_queue<pair <int, int>> pq;
    pq.push({0, x});

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (d[curr] < dist)
            continue;

        for (int i = 0; i < graph[op][curr].size(); i++)
        {
            int nextDist = dist + graph[op][curr][i].first;
            int next = graph[op][curr][i].second;

            if (nextDist < d[next])
            {
                d[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
        
    }
    return d;
}

void Input()
{
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        // 정방향
        graph[0][a].push_back({t, b});
        // 역방향
        graph[1][b].push_back({t, a});
    }
}

void Solution()
{
    vector<int> d1 = dijkstra(1);
    vector<int> d2 = dijkstra(0);
    
    for (int i = 1; i <= n; i++)
    {
        MAX = max(MAX, d1[i] + d2[i]);
    }
    
    cout << MAX << '\n';
    
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}