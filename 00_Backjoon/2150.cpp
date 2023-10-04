#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;

int v, e;
bool visited[10001];
int group[10001];
vector<int> edge[10001];
vector<int> revEdge[10001];
vector<int> scc[10001];
stack<int> st;

int scc_cnt = 0;

void dfs(int node)
{
    visited[node] = true;
    for (auto& next : edge[node])
    {
        if (!visited[next])
            dfs(next);
    }
    // dfs가 종료되는 순대로 저장
    st.push(node);
}
void dfsRev(int node)
{
    visited[node] = true;
    group[node] = scc_cnt;
    scc[scc_cnt].push_back(node);
    for (auto& next : revEdge[node])
    {
        if (!visited[next])
            dfsRev(next);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        revEdge[b].push_back(a);
    }
    
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    for (int i = 1; i <= v; i++)
        visited[i] = false;
    
    while (!st.empty())
    {
        int st_top = st.top();
        st.pop();
        if (!visited[st_top])
        {
            scc_cnt++;
            dfsRev(st_top);
            sort(scc[scc_cnt].begin(), scc[scc_cnt].end());
        }
    }
    sort(scc + 1, scc + scc_cnt + 1, [](vector<int> &i, vector<int> &j){ return i[0] < j[0]; });

    cout << scc_cnt << '\n';
    for (int i = 1; i <= scc_cnt; i++)
    {
        for (auto& next : scc[i])
            cout << next << ' ';
        cout << -1 << '\n';
    }

    return 0;
}