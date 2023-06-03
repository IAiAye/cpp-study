// 시간 초과 발생

#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int arr[5000000];
int d[5000000];

int minIndex = -1;

int FindMin(int start, int end)
{
    int minValue = 1000000001;
    for (int i = start; i <= end; i++)
    {
        if (i < 0) continue;
        if (minValue >= arr[i])
        {
            minValue = arr[i];
            minIndex = i;
        }
    }
    return minValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
    
    int start = 1 - L;
    int end = 0;

    d[0] = FindMin(start, end);

    start++;
    end++;
    while (end != N)
    {
        //최소값이 범위를 벗어났을 때
        if (minIndex < start) d[end] = FindMin(start, end);
        // 새로 들어온 수가 최소가 되었을 때
        else if (arr[end] < d[end - 1])
        {
            d[end] = arr[end];
            minIndex = end;
        }
        // 범위 안에 최소값이 있고, 새로 들어온 수도 최소가 아닐때
        else d[end] = d[end - 1];

        start++;
        end++;
    }
    
    for (int i = 0; i < N; i++)
    {
        std::cout << d[i] << ' ';
    }
    

    return 0;
}

//새로운 수가 최소 -> 나갈때까지 새로운 수끼리만 비교
//나가게 되면 그 범위안에서 최소를 다시 찾고, 그 인덱스 확인