#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> graph[101];
int isConnected[101][101];
int n;

void bfs(int start)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        for (int i = 0; i < graph[num].size(); i++)
        {
            int next = graph[num][i];
            if (!visited[next])
            {
                visited[next] = true;
                isConnected[start][next] = 1;
                q.push(next);
            }
        }
        
    }
}

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            cin >> num;
            if (num)
                graph[i].push_back(j);
        }
    }
}

void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << isConnected[i][j] << ' ';
        }
        cout << '\n';
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