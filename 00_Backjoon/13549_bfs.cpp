#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, k;
// 방문한 시간을 기록
int visited[100001];
// 좌표으로 큐 구성, 시간이 적을수록 앞으로 입력하므로 시간 기록이 필요없다.
deque <int> dq;
void bfs()
{
    // 기존 배열이 0으로 선언되있기때문에 구별해주기 위함. 1로 시작
    visited[n] = 1;
    dq.push_back(n);

    while(!dq.empty())
    {
        int pos = dq.front();

        if (pos == k)
        {
            // 1로 시작했으므로 1을 빼준다.
            cout << visited[pos] - 1 << '\n';
            return;
        }
        dq.pop_front();

        if (pos * 2 <= 100000 && !visited[pos * 2])
        {
            dq.push_front(pos * 2);
            // 비용이 적은 순대로 덱을 탐색하므로 O(E)
            // 덱에 들어갈수 있는 최대 숫자는 N이므로 O(N), 따라서 O(N + E)
            visited[pos * 2] = visited[pos];
        }
        if (pos + 1 <= 100000 && !visited[pos + 1])
        {
            dq.push_back(pos + 1);
            visited[pos + 1] = visited[pos] + 1;
        }
        if (pos - 1 >= 0 && !visited[pos - 1])
        {
            dq.push_back(pos - 1);
            visited[pos - 1] = visited[pos] + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    bfs();

    return 0;
}