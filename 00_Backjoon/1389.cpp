#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
int n, m;

int bfs(int start)
{
    vector<bool> visited(n + 1, false);

    queue<pair <int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    int sum = 0;
    while (!q.empty())
    {
        int cur = q.front().first;
        int num = q.front().second;

        q.pop();
        sum += num;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push({next, num + 1});
            }
        }
    }
    
    return sum;
}

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void Solution()
{
    int minNum = 1000;
    int minIdx = -1;
    for (int i = 1; i <= n; i++)
    {
        int BFS = bfs(i);
        if (BFS < minNum)
        {
            minNum = BFS;
            minIdx = i;
        }
    }
    cout << minIdx << '\n';
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