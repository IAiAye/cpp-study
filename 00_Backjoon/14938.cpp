#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

#define INF 1000000

int n, m, r;
int item[101];
vector<pair<int, int>> graph[101];

int dijkstra(int start)
{
    priority_queue<pair <int, int>> pq;
    vector<int> d(n + 1, INF);

    int sum = 0;
    d[start] = 0;

    pq.push({0, start});

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (d[curr] < dist)
            continue;

        if (dist > m)
            return sum;
        
        sum += item[curr];

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
    return sum;
}

void Input()
{
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }
    for (int i = 1; i <= r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({l, b});
        graph[b].push_back({l, a});
    }
}

void Solution()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dijkstra(i));
    }
    cout << ans << '\n';
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