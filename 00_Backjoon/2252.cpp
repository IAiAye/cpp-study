#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<int> times(n + 1, 0);
    vector<int> indegree(n + 1, 0);
    vector<int> edge[32001];

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        indegree[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    vector<int> ans;

    while (!q.empty())
    {
        int here = q.front();
        ans.push_back(here);
        q.pop();
        for (auto& it : edge[here])
        {
            if (--indegree[it] == 0)
                q.push(it);
        }
    }
    
    for (auto& h : ans)
        cout << h << ' ';
    cout << '\n';

    return 0;
}