#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
int arr[100001];
int visited[100001];
vector <int> graph[100001];

void dfs(int n)
{
    visited[n] = true;
    for (int i = 0; i < graph[n].size(); i++)
    {
        int next = graph[n][i];
        // visited라면 부모 노드
        if (!visited[next])
        {
            // next의 부모 저장
            arr[next] = n;
            dfs(next);
        }
    }
}

void Input()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void Solution()
{    
    dfs(1);
    for (int i = 2; i <= n; i++)
    {
        cout << arr[i] << '\n';
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