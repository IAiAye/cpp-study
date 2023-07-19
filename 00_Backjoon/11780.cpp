#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int INF = 200000000;
int n, m;
// 도착 도시, 비용
vector <pair <int, int>> graph[101];
int adj[101][101];
int path[101][101];

void Floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    // i, j 사이에는 k가 존재한다.
                    path[i][j] = k;
                }
            }
        }
    }
}

void FindPath(int from, int to, vector<int>& v)
{
    int mid = path[from][to];

    // 연결이 안되어있다.
    if (mid == 0) return;

    // from과 to 사이에 아무것도 없을 때
    if (mid == from)
    {
        v.push_back(from);
        return;
    }
    
    FindPath(from, mid, v);
    FindPath(mid, to, v);
}

void Print(int Start, int End)
{
    vector <int> path_V;
    FindPath(Start, End, path_V);
    // from ~ to 에서 from만 추가해주었으므로 마지막에 End 추가
    path_V.push_back(End);

    if (path_V.size() == 1)
    {
        cout << 0 << '\n';
        return;
    }
    cout << path_V.size() << ' ';
    for (int i = 0; i < path_V.size(); i++)
    {
        cout << path_V[i] << ' ';
    }
    cout << '\n';
}

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 동일 노선에 가중치가 더 높은 것이 들어올 수 도 있다.
        adj[a][b] = min(c, adj[a][b]);
        path[a][b] = a;
    }
}

void Solution()
{    
    Floyd();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] != INF) cout << adj[i][j] << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            Print(i, j);
        }
    }
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