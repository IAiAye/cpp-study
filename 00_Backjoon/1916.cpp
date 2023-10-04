#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define INF 100000001
int n, m;
int start, dest;
vector<pair <int, int>> graph[1001];
int d[1001];

void dijkstra(int start)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
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

        if (curr == dest)
        {
            cout << dist << '\n';
            return;
        }

        for (auto p : graph[curr])
        {
            int nextDist = p.first + dist;
            int next = p.second;

            if (nextDist < d[next])
            {
                d[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
}

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }   
    cin >> start >> dest;
}

void Solution()
{
    dijkstra(start);
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