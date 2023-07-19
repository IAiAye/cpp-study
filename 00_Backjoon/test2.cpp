#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>
using namespace std;

int f(int s, int e, int n, vector<vector<pair<int, int>>>& graph) 
{
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>> pq;
    pq.push({-2000000000, s});
    int res = 2000000000;
    
    while (!pq.empty()) {
        int vol = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        
        if (visited[node]) continue;
        visited[node] = true;
        
        res = min(res, vol);
        //cout << res << '\n';
        
        if (node == e) return res;
        
        for (auto& neighbor : graph[node]) 
        {
            int nextNode = neighbor.first;
            int nextVol = neighbor.second;
            pq.push({-nextVol, nextNode});
        }
    }
    return res;
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        cin >> c[i];
    }
    
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) 
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    
    vector<vector<int>> cc(k + 1);
    for (int i = 1; i <= n; i++) 
    {
        cc[c[i]].push_back(i);
    }
    
    for (int i = 1; i <= k; i++) 
    {
        int res = 0;
        for (int j = 0; j < cc[i].size(); j++) 
        {
            for (int k = 0; k < j; k++) 
            {
                // 시작, 끝
                res += f(cc[i][j], cc[i][k], n, graph);
                //cout << f(cc[i][j], cc[i][k], n, graph) << '\n';
            }
        }
        cout << res << '\n';
    }
    
    return 0;
}