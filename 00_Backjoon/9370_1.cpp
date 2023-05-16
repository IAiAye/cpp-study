#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;

int INF = 50000002;

int T;
int n, m, t;
int s, g, h;

int d[2001];
bool candidates[2001];
vector <pair <int, int>> graph[2001];

void dijkstra(int start)
{
    d[start] = 0;

    priority_queue <pair <int, int>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int current_pos = pq.top().second;

        pq.pop();

        for (auto iter = graph[current_pos].begin(); iter != graph[current_pos].end(); iter++)
        {
            int next_dist = dist + (*iter).first;
            int next_pos = (*iter).second;
            if (d[next_pos] > next_dist)
            {
                d[next_pos] = next_dist;
                pq.push({next_dist, next_pos});
            }
        }
    }
}

int main()
{
    system_clock::time_point start_time = system_clock::now(); // 코드 시작 시간

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--)
    {
        
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        // 초기화
        for (int i = 1; i <= n; i++)
        {
            d[i] = INF;
            candidates[i] = false;
            vector <pair <int, int>>().swap(graph[i]);
        }
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            if ((a == g && b == h) || (a == h && b == g)) d = d * 2 - 1;
            else d = d * 2;
            graph[a].push_back({d, b});
            graph[b].push_back({d, a});
        }
        for (int i = 0; i < t; i++)
        {
            int x;
            cin >> x;
            candidates[x] = true;
        }
        dijkstra(s);

        for (int i = 1; i <= n; i++)
        {
            if (candidates[i])
            {
                if (d[i] % 2 == 1) cout << i << ' ';
            }
        }
        cout << '\n';
    }

    system_clock::time_point end_time = system_clock::now(); // 코드 종료 시간
    milliseconds mill = duration_cast<milliseconds> (end_time - start_time);
    cout << "걸린 시간 : " << mill.count() << " ms" << '\n';

    return 0;
}