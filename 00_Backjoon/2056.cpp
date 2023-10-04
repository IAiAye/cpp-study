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

    int n;
    cin >> n;

    queue<int> q;
    vector<int> times(n + 1, 0);
    vector<int> indegree(n + 1, 0);
    vector<int> edge[10001];

    for (int i = 1; i <= n; i++)
    {
        cin >> times[i];
        cin >> indegree[i];
        for (int j = 0; j < indegree[i]; j++)
        {
            int pre;
            cin >> pre;
            edge[pre].push_back(i);
        }
        if (indegree[i] == 0)
            q.push(i);
    }
    
    vector<int> dp(n + 1, 0);
    int ans = 0;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        dp[here] += times[here];
        ans = max(dp[here], ans);
        for (auto& it : edge[here])
        {
            dp[it] = max(dp[it], dp[here]);
            if (--indegree[it] == 0)
                q.push(it);
        }
    }
    cout << ans << '\n';


    return 0;
}