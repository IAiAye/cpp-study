#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
vector<int> graph[300001];
bool visited[300001];
queue<pair <int,int>> q;
vector<int> ans;

void bfs(int start)
{
    visited[start] = true;
    q.push(make_pair(start, 0));
    while (!q.empty())
    {
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (dist == k)
        {
            ans.push_back(now);
            continue;
        }
        else if (dist > k)
            continue;

        int size = graph[now].size();
        for (int i = 0; i < size; i++)
        {
            int next = graph[now][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push(make_pair(next, dist + 1));
            }
        }
    }
}

void Input()
{
    // n = 4;
    // m = 4;
    // k = 2;
    // x = 1;
    // graph[1].push_back(2);
    // graph[1].push_back(3);
    // graph[2].push_back(3);
    // graph[2].push_back(4);

    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
}

void Solution()
{
    bfs(x);
    if (ans.empty())
        cout << -1 << '\n';
    else
    {
        sort(ans.begin(), ans.end());
        int size = ans.size();
        for (int i = 0; i < size; i++)
            cout << ans[i] << '\n';
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