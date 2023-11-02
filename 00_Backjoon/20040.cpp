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
    parent.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    
}

void Solution()
{
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (Find(a) == Find(b))
        {
            ans = i + 1;
            break;
        }
        else
        {
            Union(a, b);
        }
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