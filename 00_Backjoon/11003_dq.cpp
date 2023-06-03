#include <iostream>
#include <algorithm>
#include <deque>

#define MAX 5000010
using namespace std;

int N, L;
int arr[MAX];

void Input()
{
    std::cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
}

void Solution()
{
    // 그 위치의 값과, 위치의 인덱스 저장
    deque <pair <int, int>> dq;

    for (int i = 0; i < N; i++)
    {
        int start = 1 - L + i;
        int end = i;

        // 최소값이 범위에서 벗어났을 때
        if (!dq.empty() && dq.front().second < start) dq.pop_front();

        // 새로운 값이 제일 작다면, 덱을 다 비울 것이고, 아니라면 최소값 후보들 중 큰 것들만 날릴 것이다.
        while (!dq.empty() && dq.back().first > arr[end]) dq.pop_back();

        dq.push_back({arr[end], end});

        std::cout << dq.front().first << ' ';
    }
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