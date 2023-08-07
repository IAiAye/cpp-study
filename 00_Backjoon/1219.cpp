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
#define INF 2500000000

int n, s, e, m;
int earn[50];
bool visited[50];
vector<ll> dist(50, INF);
vector<pair <int, int>> graph[50];
queue<int> cycleNode;

bool BFS()
{
    while (!cycleNode.empty())
    {
        int current = cycleNode.front();
        cycleNode.pop();

        for (auto x : graph[current])
        {
            int next = x.first;
            if (visited[next])
                continue;
            visited[next] = true;
            cycleNode.push(next);
        }
    }
    if (visited[e])
        return true;
    return false;
}

void Input()
{
    cin >> n >> s >> e >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    for (int i = 0; i < n; i++)
    {
        cin >> earn[i];
    }
}

void Solution()
{
    dist[s] = -earn[s];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (auto current : graph[j])
            {
                int next = current.first;
                ll nextCost = current.second;

                ll nextDist = dist[j] + nextCost - earn[next];
                if (dist[j] != INF && dist[next] > nextDist)
                {
                    dist[next] = nextDist;
                    if (i == n - 1)
                    {
                        visited[j] = true;
                        cycleNode.push(j);
                    }
                }
            }
        }
    }
    if (dist[e] == INF)
        cout << "gg" << '\n';
    else
    {
        if (BFS())
            cout << "Gee" << '\n';
        else   
            cout << -dist[e] << '\n';
    }
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