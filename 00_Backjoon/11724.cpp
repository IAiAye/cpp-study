#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector <int> graph[1001];
bool visited[1001];

void dfs(int n)
{
    visited[n] = true;

    for (int i = 0; i < graph[n].size(); i++)
    {
        int nextNode = graph[n][i];
        if (!visited[nextNode]) dfs(nextNode);
    }
}

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
}

void Solution()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
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