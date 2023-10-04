#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;

#define MAX_N 200001
#define MAX_M 500001

int n, m;
bool visited[MAX_N];
bool finished[MAX_N];
int group[MAX_N];
int node_id[MAX_N];

vector<int> edge[MAX_M];
vector<int> scc[MAX_M];
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
            // scc[scc_cnt].push_back(top);
            // group[top] = scc_cnt;
            finished[top] = true;
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

    cin >> n >> m;
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

    // sort(scc + 1, scc + scc_cnt + 1, [](vector<int> &i, vector<int> &j){ return i[0] < j[0]; });

    // cout << scc_cnt << '\n';

    if (scc_cnt == 1)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';

    return 0;
}