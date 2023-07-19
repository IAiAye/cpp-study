#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, maxCost;
int maxNode;
int visited[100001];
vector <pair <int, int>> graph[100001];

void dfs(int n, int cost)
{
    visited[n] = true;
    for (int i = 0; i < graph[n].size(); i++)
    {
        int next = graph[n][i].first;
        int nextCost = graph[n][i].second + cost;
        
        if (!visited[next])
        {
            if (nextCost > maxCost)
            {
                maxCost = nextCost;
                maxNode = next;
            }
            
            dfs(next, nextCost);
        }
    }
}

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int Start;
        cin >> Start;

        while (true)
        {
            int End, Cost;
            cin >> End;
            
            if (End == -1) break;
            
            cin >> Cost;
            graph[Start].push_back({End, Cost});
        }
    }
}

void Solution()
{    
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    
    dfs(maxNode, 0);

    cout << maxCost << '\n';
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
    
    return 0;
}