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
vector<pair <int,int>> graph[1001];
bool visited[1001];

int dijkstra(int start, int op)
{
    vector<int> d(n + 1, INF);
    d[start] = 0;

    priority_queue<pair <int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (d[curr] < dist)
            continue;

        if (op == 0 && !visited[curr])
        {
            visited[curr] = true;
            MAX = max(MAX, dijkstra(curr, 1) + dist);
        }

        if (op == 1 && curr == x)
            return dist;
        

        for (int i = 0; i < graph[curr].size(); i++)
        {
            int nextDist = dist + graph[curr][i].first;
            int next = graph[curr][i].second;

            if (nextDist < d[next])
            {
                d[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
        
    }
    return 0;
}

void Input()
{
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({t, b});
    }
}

void Solution()
{
    dijkstra(x, 0);
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