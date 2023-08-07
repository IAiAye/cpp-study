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
vector<int> capacity;

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
        capacity[pb] += capacity[pa];
        return pb;
    }
    return pb;
}

void Input()
{
    cin >> n >> m;
    parent.resize(n + 1);
    sz.resize(n + 1);
    capacity.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> capacity[i];
    for (int i = 1; i <= n; i++)
    {
        int rain;
        cin >> rain;
        capacity[i] -= rain;
    }
}

void Solution()
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (capacity[i] < 0)
            cnt++;
    }
    
    while (m--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int a, b;
            cin >> a >> b;

            int pa = Find(a);
            int pb = Find(b);

            // 두 도시 다 홍수가 났거나, 안났을 때
            if ((capacity[pa] < 0 && capacity[pb] < 0) || (capacity[pa] >= 0 && capacity[pb] >= 0))
                Union(pa, pb);
            else
            {
                if (capacity[pa] < 0)
                    cnt -= sz[pa];
                else
                    cnt -= sz[pb];
                
                int p = Union(pa, pb);

                if (capacity[p] < 0)
                    cnt += sz[p];
            }
        }
        else
            cout << cnt << '\n';
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