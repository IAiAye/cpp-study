#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;

priority_queue <pair <int, int>> pq;
int t[100001];
int INF = 100001;

void dijkstra(int start)
{
    for (int i = 0; i <= 100000; i++)
    {
        t[i] = INF;
    }
    t[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        // 최소 힙으로 구현하기 위해 음수로 표현
        int time = -pq.top().first;
        int pos = pq.top().second;

        // if (time == 1)
        // {
        //     cout << time << ' ' << pos << '\n';
        // }
        
        if (pos == k)
        {
            cout << time << '\n';
            return;
        }
        pq.pop();

        // 이미 pos까지 도달하는 시간이 현재 간선보다 짧다면 패스
        if (t[pos] < time) continue;
        if (pos * 2 < INF)
        {
            int next_time = time;
            int next_pos = pos * 2;
            
            if (next_time < t[next_pos])
            {
                t[next_pos] = next_time;
                pq.push({-next_time, next_pos});
            }
        }
        if (pos + 1 < INF)
        {
            int next_time = time + 1;
            int next_pos = pos + 1;
            if (next_time < t[next_pos])
            {
                t[next_pos] = next_time;
                pq.push({-next_time, next_pos});
            }
        }
        if (pos - 1 >= 0)
        {
            int next_time = time + 1;
            int next_pos = pos - 1;
            if (next_time < t[next_pos])
            {
                t[next_pos] = next_time;
                pq.push({-next_time, next_pos});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    dijkstra(n);

    return 0;
}