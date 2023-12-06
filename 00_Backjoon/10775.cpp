#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 100001
int parent[MAX];

int g,p;

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

    if (pa > pb)
        swap(pa, pb);

    parent[pb] = pa;
}

void Input()
{
    cin >> g >> p;
}

void Solution()
{
    int cnt = 0;
    for (int i = 1; i <= g; i++)
        parent[i] = i;

    for (int i = 0; i < p; i++)
    {
        int gi;
        cin >> gi;
        int pg = Find(gi);

        if (pg == 0)
            break;
        
        Union(pg - 1, pg);
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