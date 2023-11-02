#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n, m;
vector<pair <int, pair<int, int>>> graph;
vector<int> parent;
vector<int> sz;

int Find(int a)
{
    if (parent[a] != a)
        return parent[a] = Find(parent[a]);
    return a;
}

void Union(int a, int b)
{
    int pa = Find(a);
    int pb = Find(b);
    if (sz[pa] > sz[pb])
        swap(pa, pb);
    if (pa != pb)
    {
        parent[pa] = pb;
        sz[pb] += sz[pa];
    }
}

bool cmp(pair <int, pair<int, int>>& a, pair <int, pair<int, int>>& b)
{
    return a.first < b.first;
}

void Input()
{
    cin >> n >> m;
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
}

void Solution()
{
    sort(graph.begin(), graph.end(), cmp);

    int sum = 0;
    int lastCost = 0;
    for (int i = 0; i < m; i++)
    {
        int cost = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if (Find(a) == Find(b))
            continue;
        
        Union(a, b);
        sum += cost;
        lastCost = cost;
    }
    cout << sum - lastCost << '\n';
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