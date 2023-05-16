#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;

int INF = 50000001;
int n, m, t;
int s, g, h;

// 연결된 정점과 간선의 가중치
vector <pair <int, int>> graph[2001];
// 시작 정점에서 가는데 걸리는 최소 가중치
int d[2001];
int ans[2001];

void dijkstra(int start)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    
    d[start] = 0;
    // 우선순위 큐, 최대 힙을 의미한다.
    // 가중치가 최소가 되는 순대로 정렬. 음수를 이용해 최소 힙을 구현
    priority_queue <pair <int, int>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        // 최대 힙에서 거리가 짧은 것이 먼저 올라오게 하기 위해 음수화
        int distance = -pq.top().first;
        int current = pq.top().second;
        //cout << distance << ' ' << current << ' ' << ghRoute << '\n';
        pq.pop();

        // 이미 current로 가는 거리가 하나의 간선의 거리보다 짧다면 스킵
        if (d[current] < distance) continue;
        // current에 연결된 간선들을 모두 확인
        for (int i = 0; i < graph[current].size(); i++)
        {
            // current까지의 최소 거리와 간선의 가중치와의 합
            int nextDistance = distance + graph[current][i].first;
            int next = graph[current][i].second;

            // 기존 최소 거리보다 작거나 같을때 교체, 같을때 gh를 지날수도 있으므로
            if (nextDistance < d[next])
            {   
                d[next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}


int main()
{
    system_clock::time_point start_time = system_clock::now(); // 코드 시작 시간

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        // n : 정점의 수, m : 도로의 수, t : 목적지 후보의 수
        cin >> n >> m >> t;
        // s : 출발지, g,h 사이의 도로는 필수 통과
        cin >> s >> g >> h;
        for (int i = 1; i <= n; i++)
        {
            // 모두 초기화
            ans[i] = 0;
            vector <pair <int, int>>().swap(graph[i]);
        }
        
        int first_seg;
        int second_seg;
        int third_seg;
        int thrid_point;

        // 그래프에 간선 추가
        for (int i = 1; i <= m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            if ((a == g && b == h) || (a == h && b == g)) second_seg = d;
            // a에서 b로 가는 d의 간선 추가
            graph[a].push_back({d, b});
            graph[b].push_back({d, a}); // 양방향
        }
        dijkstra(s);
        if (d[g] < d[h]) 
        {
            first_seg = d[g];
            thrid_point = h;
        }
        else 
        {
            first_seg = d[h];
            thrid_point = g;
        }
        // 목적지 후보
        for (int i = 1; i <= t; i++)
        {
            int fourth_point;
            cin >> fourth_point;
            ans[fourth_point] = d[fourth_point];
        }

        dijkstra(thrid_point);
        for (int i = 1; i <= n; i++)
        {
            if (ans[i])
            {
                if (ans[i] == first_seg + second_seg + d[i])
                {
                    cout << i << ' ';
                }
            }
        }
        cout << '\n';
    }

    system_clock::time_point end_time = system_clock::now(); // 코드 종료 시간
    milliseconds mill = duration_cast<milliseconds> (end_time - start_time);
    cout << "걸린 시간 : " << mill.count() << " ms" << '\n';

    return 0;
}