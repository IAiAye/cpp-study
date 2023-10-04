#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n, k;

void Input()
{
    cin >> n >> k;
}

void Solution()
{
    queue<int> q;
    q.push(n);

    vector<int> dp(100001, 100001);
    dp[n] = 0;
    
    int cnt = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == k)
            break;

        if (now - 1 >= 0 && dp[now - 1] > dp[now])
        {
            dp[now - 1] = dp[now] + 1;
            q.push(now - 1);
        }
        if (now + 1 <= 100000 && dp[now + 1] > dp[now])
        {
            dp[now + 1] = dp[now] + 1;
            q.push(now + 1);
        }
        if (now * 2 <= 100000 && dp[now * 2] > dp[now])
        {
            dp[now * 2] = dp[now] + 1;
            q.push(now * 2);
        }
    }
    // k에 도달 했을 때, 횟수가 같은 큐만 확인
    while (!q.empty() && dp[q.front()] == dp[k])
    {
        if (q.front() == k)
            cnt++;
        q.pop();
    }
    cout << dp[k] << '\n' << cnt << '\n';
    
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