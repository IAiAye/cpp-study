#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;
using ll = long long;
#define MAX 100001
#define INF 1e13+7

int n, m, d, e;
ll height[MAX];
vector <pair <ll, int>> route[MAX];
ll dist[MAX][2];
ll value;

void Dijkstra(int start, int k)
{
    priority_queue<pair <ll, int>, vector<pair <ll, int>>, greater<pair <ll, int>>> pq;
    pq.push(make_pair(0, start));
    dist[start][k] = 0;

    while (!pq.empty())
    {
        int curr = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if (cost > dist[curr][k])
            continue;

        int size = route[curr].size();
        for (int i = 0; i < size; i++)
        {
            int next = route[curr][i].second;
            ll nextCost = route[curr][i].first + cost;

            if (dist[next][k] > nextCost && height[next] > height[curr])
            {
                dist[next][k] = nextCost;
                pq.push(make_pair(nextCost, next));
            }
        }
    }
}

void findAns()
{
    ll maxIdx = -INF * 100000;
    for (int i = 1; i <= n; i++)
        maxIdx = max(maxIdx, height[i] * e - d * (dist[i][0] + dist[i][1]));
    if (maxIdx == -INF * 100000)
        cout << "Impossible" << '\n';
    else
        cout << maxIdx << '\n';
    
}

void Input()
{
    cin >> n >> m >> d >> e;
    for (int i = 1; i <= n; i++)
        cin >> height[i];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        route[a].push_back(make_pair(c, b));
        route[b].push_back(make_pair(c, a));
    }
    for (int i = 0; i <= n; i++)
    {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
}

void Solution()
{
    Dijkstra(1, 0);
    Dijkstra(n, 1);
    findAns();
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