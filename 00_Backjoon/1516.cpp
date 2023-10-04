#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> times(n + 1, 0);
    vector<int> indegree(n + 1, 0);
    vector<int> edge[501];
    for (int i = 1; i <= n; i++)
    {
        cin >> times[i];
        while (true)
        {
            int a;
            cin >> a;
            if (a == -1)
                break;

            edge[a].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> dp(n + 1, 0);

    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        dp[here] += times[here];
        for (auto& next : edge[here])
        {
            dp[next] = max(dp[next], dp[here]);
            if (--indegree[next] == 0)
                q.push(next);
        }
    }
    
    for (int i = 1; i <= n; i++)
        cout << dp[i] << '\n';

    return 0;
}