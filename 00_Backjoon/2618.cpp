#include <iostream>
#include <algorithm>
using namespace std;

int n, w;
// event[][0] : x, [1] : y
int event[1002][2];
// cache[A][B]는 1번 경찰차가 A케이스, 2번 경찰차가 B케이스까지 해결했을때의 최단 거리다.
int cache[1001][1001];

int findDist(int pos1, int pos2)
{
    return abs(event[pos1][0] - event[pos2][0]) + abs(event[pos1][1] - event[pos2][1]);
}

// 사건 번호를 인자로 받는다. 앞의 인자는 경찰차 1이 위치한 사건번호, 뒤의 인자는 경찰차 2가 위치한 사건번호다.
// 현재 위치한 사건 번호에서 끝까지 갔을때 최단거리를 계산한다.
int minPath(int event1, int event2)
{
    // 마지막 사건에 도달하면 종료
    if (event1 == w || event2 == w) 
    {
        cache[event1][event2] = 0;
        return 0;
    }
    if (cache[event1][event2] != -1) return cache[event1][event2];
    
    int nextEvent = max(event1, event2) + 1;

    int dist1, dist2;

    // 경찰차 1이 움직일 때
    if (event1 == 0) dist1 = findDist(0, nextEvent);
    else dist1 = findDist(event1, nextEvent);

    // 경찰차 2가 움직일 때
    if (event2 == 0) dist2 = findDist(1001, nextEvent);
    else dist2 = findDist(event2, nextEvent);

    int result1 = dist1 + minPath(nextEvent, event2);
    int result2 = dist2 + minPath(event1, nextEvent);
    
    cache[event1][event2] = min(result1, result2);
    
    return cache[event1][event2];
}

void findPath(int event1, int event2)
{
    // 마지막 사건에 도달하면 종료
    if (event1 == w || event2 == w) return;
    
    int nextEvent = max(event1, event2) + 1;

    int dist1, dist2;

    // 경찰차 1이 움직일 때
    if (event1 == 0) dist1 = findDist(0, nextEvent);
    else dist1 = findDist(event1, nextEvent);

    // 경찰차 2가 움직일 때
    if (event2 == 0) dist2 = findDist(1001, nextEvent);
    else dist2 = findDist(event2, nextEvent);

    int result1 = dist1 + cache[nextEvent][event2];
    int result2 = dist2 + cache[event1][nextEvent];
    
    if (result1 < result2)
    {
        std::cout << 1 << '\n';
        findPath(nextEvent, event2);
    }
    else
    {
        std::cout << 2 << '\n';
        findPath(event1, nextEvent);
    }
}

void Input()
{
    std::cin >> n >> w;
    for (int i = 1; i <= w; i++)
    {
        std::cin >> event[i][0] >> event[i][1];
    }
    // 초기 경찰차의 위치 설정
    event[0][0] = 1;
    event[0][1] = 1;
    event[1001][0] = n;
    event[1001][1] = n;
}

void Solution()
{
    for (int i = 0; i <= w; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            cache[i][j] = -1;
        }
    }
    std::cout << minPath(0, 0) << '\n';
    findPath(0, 0);
    std::cout << '\n';
    // for (int i = 0; i <= w; i++)
    // {
    //     for (int j = 0; j <= w; j++)
    //     {
    //         std::cout << cache[i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}