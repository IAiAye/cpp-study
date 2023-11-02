#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int tc;

int DFS(int node, vector<vector <int>>& graph, vector<int>& t, vector<bool>& visited, vector<int>& psum)
{
    if (visited[node])
    {
        return psum[node];
    }
    if (graph[node].empty())
    {
        visited[node] = true;
        psum[node] = t[node];
        return t[node];
    }

    int MAX = 0;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i];
        MAX = max(MAX, DFS(child, graph, t, visited, psum));
    }
    
    visited[node] = true;
    psum[node] = MAX + t[node];
    return MAX + t[node];
}

void Input()
{
    cin >> tc;
}

void Solution()
{
    while (tc--)
    {
        int n, k, w;
        cin >> n >> k;
        vector<int> t(n + 1, 0);
        vector<bool> visited(n + 1, 0);
        vector<int> psum(n + 1, 0);
        vector<vector <int>> graph(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> t[i];
        }
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[y].push_back(x);
        }
        cin >> w;

        cout << DFS(w, graph, t, visited, psum) << '\n';
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