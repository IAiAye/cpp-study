#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
using ll = long long;

int n;
vector<pair <double, double>> pos;

vector<pair <double, pair<int, int>>> graph;
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

bool cmp(pair <double, pair<int, int>>& a, pair <double, pair<int, int>>& b)
{
    return a.first < b.first;
}

void Input()
{
    cin >> n;

    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        // x *= 100;
        // y *= 100;
        pos.push_back({x, y});
    }
}

void Solution()
{
    for (int i = 0; i < n - 1; i++)
    {
        int x1 = pos[i].first;
        int y1 = pos[i].second;

        for (int j = i + 1; j < n; j++)
        {
            int x2 = pos[j].first;
            int y2 = pos[j].second;

            double l = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

            graph.push_back({l, {i + 1, j + 1}});
        }
    }
    sort(graph.begin(), graph.end(), cmp);

    double sum = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        double l = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if (Find(a) == Find(b))
            continue;
        
        Union(a, b);
        sum += l;
    }
    cout << fixed;
    cout.precision(2);
    cout << sum << '\n';
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