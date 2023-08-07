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
vector<array <int, 3>> edge;

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

void Input()
{
    cin >> n;
    // 0번에 수원이 있다고 가정
    for (int i = 1; i <= n; i++)
    {
        int cost;
        cin >> cost;
        edge.push_back({cost, 0, i});
    }
    
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cost;
            cin >> cost;
            if (i != j)
                edge.push_back({cost, i, j});
        }
    }
    
    sort(edge.begin(), edge.end());

    ll sum = 0;
    for (auto [w, u, v] : edge)
    {
        if (Union(u, v))
            sum += w;
    }
    cout << sum << '\n';
}

void Solution()
{

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