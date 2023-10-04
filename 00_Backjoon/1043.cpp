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
vector<vector <int>> party;

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
    int known;
    cin >> known;
    for (int i = 0; i < known; i++)
    {
        int num;
        cin >> num;
        Union(0, num);
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        vector<int> p;

        int curr;
        int prev;
        cin >> curr;
        p.push_back(curr);
        for (int j = 1; j < num; j++)
        {
            prev = curr;
            cin >> curr;

            Union(prev, curr);
        }
        party.push_back(p);
    }
    int cnt = 0;
    for (auto p : party)
    {
        if (Find(0) != Find(p[0]))
            cnt++;
    }
    cout << cnt << '\n';
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