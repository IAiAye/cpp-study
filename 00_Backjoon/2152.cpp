#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;

#define MAX_N 10001

int n, m, s, t;
bool visited[MAX_N];
bool finished[MAX_N];
int group[MAX_N];
int node_id[MAX_N];
int scc_indgree[MAX_N];
int scc_size[MAX_N];
int dp[MAX_N];
int come_from[MAX_N];

vector<int> edge[MAX_N];
vector<int> scc[MAX_N];
vector<int> scc_edge[MAX_N];
stack<int> st;

int scc_cnt = 0;
int id = 0;

int dfs(int node)
{
    visited[node] = true;
    int parent = node_id[node] = ++id;
    st.push(node);

    for (auto& next : edge[node])
    {
        if (!visited[next])
            parent = min(parent, dfs(next));
        // SCC가 만들어지지 않았다면,
        else if (!finished[next])
            parent = min(parent, node_id[next]);
    }
    if (parent == node_id[node])
    {
        scc_cnt++;
        while (true)
        {
            int top = st.top();
            st.pop();

            group[top] = scc_cnt;
            finished[top] = true;
            scc_size[scc_cnt]++;

            // scc[scc_cnt].push_back(top);
            if (top == node)
                break;
        }
        // sort(scc[scc_cnt].begin(), scc[scc_cnt].end());
    }
    return parent;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (auto& next : edge[i])
        {
            // 다른 SCC에 속할 때
            if (group[next] != group[i])
            {
                // SCC끼리 연결
                scc_edge[group[i]].push_back(group[next]);
            }
        }
    }

    s = group[s];
    t = group[t];

    dp[s] = scc_size[s];
    for (int i = s; i >= t; i--)
    {
        if (dp[i] == 0)
            continue;

        for (auto& next : scc_edge[i])
            dp[next] = max(dp[next], dp[i] + scc_size[next]);
    }
    cout << dp[t] << '\n';

    return 0;
}