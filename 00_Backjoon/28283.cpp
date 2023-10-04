#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 500001
#define INF 250000000001

int n, m, x, y;
int a, b;

bool visited[MAX];
vector<ll> d(MAX, INF);
ll money[MAX];
int vac[MAX];
vector<int> graph[MAX];

struct cmp
{
    bool operator()(ll& a, ll& b)
    {
        return a > b;
    }
};


void bfs()
{
    // time, node
    priority_queue <pair <ll,int>> pq;
    
    for (int i = 1; i <= y; i++)
    {
        visited[vac[i]] = true;
        d[vac[i] - 1] = 0;
        pq.push({0, vac[i]});
    }
    
    while(!pq.empty())
    {
        ll t = -pq.top().first;
        int cur = pq.top().second;

        pq.pop();
        
        for (auto& next : graph[cur])
        {
            if (!visited[next])
            {
                visited[next] = true;
                d[next - 1] = (t + 1) * money[next];
                pq.push({-1LL * (t + 1), next});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        cin >> money[i];
        if (money[i] == 0)
            d[i - 1] = 0;
    }
    
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= y; i++)
        cin >> vac[i];
    
    bfs();

    sort(d.begin(), d.begin() + n, cmp());

    ll sum = 0;
    bool isINF = false;
    for (int i = 0; i < x; i++)
    {
        if (d[i] == INF)
        {
            isINF = true;
            break;
        }
        sum += d[i];
    }
    if (isINF)
        cout << -1 << '\n';
    else
        cout << sum << '\n';

    return 0;
}
