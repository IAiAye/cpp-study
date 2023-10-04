#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 100001

int n, m, x;
vector<int> upward[MAX];
vector<int> downward[MAX];
bool visited[MAX];
bool revVisited[MAX];


void bfs()
{
    int cnt = 1;

    queue<int> q;
    q.push(x);
    visited[x] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < upward[cur].size(); i++)
        {
            int next = upward[cur][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
                cnt++;
            }
        }
    }
    cout << cnt << ' ';

    cnt = n;
    q.push(x);
    revVisited[x] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < downward[cur].size(); i++)
        {
            int next = downward[cur][i];
            if (!revVisited[next])
            {
                q.push(next);
                revVisited[next] = true;
                cnt--;
            }
        }
    }
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        downward[a].push_back(b);
        upward[b].push_back(a);
    }
    
    bfs();
    
    return 0;
}
