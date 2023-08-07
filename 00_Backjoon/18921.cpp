#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

int n, m;
int s, e;
vector<int> parent;
vector<int> sz;
vector<int> edgeNum;
vector<array <int, 3>> edge;

int Find(int a)
{
    if (parent[a] != a)
        return parent[a] = Find(parent[a]);
    return a;
}

int Union(int a, int b)
{
    int pa = Find(a);
    int pb = Find(b);
    if (sz[pa] > sz[pb])
        swap(pa, pb);
    if (pa != pb)
    {
        parent[pa] = pb;
        sz[pb] += sz[pa];
        edgeNum[pb] += (edgeNum[pa] + 1);
        return pb;
    }
    return pb;
}

void Input()
{
    cin >> n;
    
    edge.resize(n - 1);
    parent.resize(n + 1);
    sz.resize(n + 1);
    edgeNum.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    for (auto& [w, u, v] : edge)
        cin >> u >> v >> w;
}

void Solution()
{
    sort(edge.begin(), edge.end());

    ll MAX = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int Cost = edge[i][0];
        int a = edge[i][1];
        int b = edge[i][2];
        if (Find(a) != Find(b))
        {
            int p = Union(a, b);
            MAX = max(MAX, 1LL * edgeNum[p] * Cost);
            // cout << (sz[p] - 1) << ' ' << Cost << '\n';
        }
        else
        {
            edgeNum[Find(a)]++;
            MAX = max(MAX, 1LL * edgeNum[Find(a)] * Cost);
        }
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