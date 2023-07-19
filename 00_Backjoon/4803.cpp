#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, m;
vector<int> graph[501];
int visited[501];
int finished[501];
int graphCnt;
bool flag;

void dfs(int n, int before)
{
    visited[n] = 1;
    
    for (int i = 0; i < static_cast<int>(graph[n].size()); i++)
    {
        int next = graph[n][i];
        if (next == before)
            continue;
        if (!visited[next])
            dfs(next, n);
        // n에서 출발한 탐색이 끝나지않았는데 n으로 다시 돌아왔다. -> 사이클
        else if (!finished[next] && !flag)
        {
            flag = true;
            graphCnt++;
        }
    }
    // n에서 출발한 탐색이 끝났음을 표시
    finished[n] = true;
}

void Input()
{
    cin >> n >> m;
    int testNum = 1;
    while(n != 0 || m != 0)
    {
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        int loopCnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i, 0);
                flag = false;
                loopCnt++;
            }
        }
        int treeCnt = loopCnt - graphCnt;

        cout << "Case " << testNum << ": ";
        if (treeCnt == 0)
            cout << "No trees." << '\n';
        else if (treeCnt == 1)
            cout << "There is one tree." << '\n';
        else
            cout << "A forest of " << treeCnt << " trees." << '\n';

        graphCnt = 0;
        for (int i = 1; i <= n; i++)
            graph[i].clear();
        
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        testNum++;

        cin >> n >> m;
    }
    
}

void Solution()
{    
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