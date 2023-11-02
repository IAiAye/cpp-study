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
#define MAX 100001

int t, n, cnt;

void dfs(int curr, vector<bool>& visited, vector<bool>& finished, vector<vector<int>>& graph, stack<int>& st)
{
    visited[curr] = true;
    st.push(curr);

    for (int next : graph[curr])
    {
        if (!visited[next])
            dfs(next, visited, finished, graph, st);
        else if (!finished[next])
        {
            while (true)
            {
                int num = st.top();
                st.pop();
                cnt--;
                if (num == next)
                    break;
            }
        }
    }
    finished[curr] = true;
}

void Input()
{
    cin >> t;
}

void Solution()
{
    while (t--)
    {
        cin >> n;
        cnt = n;
        vector<int> v;
        vector<vector<int>> graph(n + 1, v);
        vector<bool> visited(n + 1);
        vector<bool> finished(n + 1);
        stack<int> st;
        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            graph[i].push_back(num);
        }
        
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i, visited, finished, graph, st);
        }
        cout << cnt << '\n';
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