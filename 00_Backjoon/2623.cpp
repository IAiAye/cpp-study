#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
using ll = long long;

int n, m;
vector<int> graph[1001];
int indegree[1001];

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        int prev;
        int curr;

        cin >> curr;
        for (int j = 1; j < num; j++)
        {
            prev = curr;
            cin >> curr;
            graph[prev].push_back(curr);
            indegree[curr]++;
        }
    }
}

void Solution()
{
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for (int i = 0; i < graph[curr].size(); i++)
        {
            int next = graph[curr][i];
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }
    if (n == ans.size())
    {
        for (int a : ans)
            cout << a << '\n';
    }
    else
        cout << 0 << '\n';
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