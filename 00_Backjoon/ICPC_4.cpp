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
vector<int> parent;
vector<int> sz;
vector<array <ll, 4>> edge;

bool cmp(array <ll, 4>&a, array <ll,4>&b)
{
    if (a[0] == b[0])
    {
        return a[3] < b[3];
    }
    return a[0] < b[0];
}

int Find(int a)
{
    if (parent[a] != a)
        return parent[a] = Find(parent[a]);
    return a;
}

bool Union(int a, int b)
{
    int pa = Find(a);
    int pb = Find(b);
    if (sz[pa] > sz[pb])
        swap(pa, pb);
    if (pa != pb)
    {
        parent[pa] = pb;
        sz[pb] += sz[pa];
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n >> m;
    edge.resize(m);
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    for (auto& [z, u, v, w] : edge)
        cin >> u >> v >> z >> w;
    
    sort(edge.begin(), edge.end(), cmp);

    ll sum = 0;
    string num = "";
    for (auto [z, u, v, w] : edge)
    {
        if (Union(u, v))
        {
            num += to_string(int(z));
            sum += w;
        }
    }
    if (num.size() == n - 1)
        cout << num << ' ' << sum << '\n';
    else    
        cout << -1 << '\n';
    
    
    
    return 0;
}