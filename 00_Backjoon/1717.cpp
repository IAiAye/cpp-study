#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

int m, n;
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
}

void Solution()
{
    for (int i = 0; i < m; i++)
    {
        int comm, a, b;
        cin >> comm >> a >> b;
        if (comm == 0)
            Union(a, b);
        else if (comm == 1)
        {
            if (Find(a) == Find(b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
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