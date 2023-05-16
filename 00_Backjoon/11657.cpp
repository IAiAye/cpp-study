#include <iostream>
#include <vector>
using namespace std;
vector <pair <int,int> > graph[501];
int INF = 900000001;
int n, m;
long long d[501];

void bellmanFord(int start)
{
    d[start] = 0;
    // n - 1번 반복
    for (int i = 1; i <= n - 1; i++)
    {
        // 모든 간선의 출발점 확인
        for (int j = 1; j <= n; j++)
        {
            // 확인되지 않은 출발점이면 통과
            if (d[j] != INF)
            {
                for (int k = 0; k < graph[j].size(); k++)
                {
                    long long next_d = d[j] + graph[j][k].first;
                    int next_pos = graph[j][k].second;

                    if (d[next_pos] > next_d) d[next_pos] = next_d;
                }
            }
            else continue;
        }
    }
    // 모든 간선의 출발점 확인
    for (int j = 1; j <= n; j++)
    {
        // 확인되지 않은 출발점이면 통과
        if (d[j] != INF)
        {
            for (int k = 0; k < graph[j].size(); k++)
            {
                long long next_d = d[j] + graph[j][k].first;
                int next_pos = graph[j][k].second;

                // n - 1 의 사이클이 돌고 또 갱신이 된다면 음의 사이클이 존재
                if (d[next_pos] > next_d)
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
        else continue;
    }
    for (int i = 2; i <= n; i++)
    {
        if (d[i] != INF) cout << d[i] << '\n';
        else cout << -1 << '\n';
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    bellmanFord(1);

    return 0;
}