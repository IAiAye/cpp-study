#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

#define MAX 30001

int n, m, k;
int parent[MAX];
int sz[MAX];
int candy[MAX];
bool visited[MAX];
int dp[MAX];

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
        candy[pb] += candy[pa];
    }
}

void Input()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
        cin >> candy[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
}

void Solution()
{
    vector<int> w;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        int p = Find(i);
        if (!visited[p])
        {
            visited[p] = true;
            w.push_back(sz[p]);
            v.push_back(candy[p]);
        }
    }
    
    for (int i = 0; i < w.size(); i++)
    {
        for (int j = k - 1; j >= 1; j--)
        {
            if (w[i] <= j)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    // k 이상이 울기 때문에
    cout << dp[k - 1] << '\n';
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