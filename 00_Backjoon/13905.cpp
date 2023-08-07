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
vector<array <int, 3>> edge;

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

void Input()
{
    cin >> n >> m;
    cin >> s >> e;
    
    edge.resize(m);
    parent.resize(n + 1);
    sz.resize(n + 1);
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
    bool flag = false;
    sort(edge.begin(), edge.end());
    for (int i = m - 1; i >= 0; i--)
    {
        int Cost = edge[i][0];
        int a = edge[i][1];
        int b = edge[i][2];
        if (Find(a) != Find(b))
            Union(a, b);
        else
            continue;
        
        if (Find(s) == Find(e))
        {
            cout << Cost << '\n';
            flag = true;
            break;
        }
    }
    if (flag == false)
        cout << 0 << '\n';
    
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