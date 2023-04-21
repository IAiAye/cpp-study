#include <iostream>
#include <algorithm>
using namespace std;
long long heights[100001];

// 분할정복 + 그리디, 총 시간복잡도 O(NlogN)
long long solve(int left, int right)
{
    if (left == right)
    {
        return heights[left];
    }
    int mid = left + (right - left) / 2;
    // 가운데를 기준으로 분할정복 , O(log N)
    long long ans = max(solve(left, mid), solve(mid + 1, right)); 

    // 가운데를 포함한 넓이 중 최대 넓이 찾기
    int lpos = mid;
    int rpos = mid + 1;
    long long min_height = 1000000001;
    // left, right의 범위 안에서 계산
    while (left <= lpos && rpos <= right) // O(N)
    {
        min_height = min({min_height, heights[lpos], heights[rpos]});
        // min_height가 int라면 곱하는 과정에서 오버플로우가 발생할 수 있다.
        ans = max(ans, ((rpos - lpos + 1) * min_height));

        if (left == lpos) ++rpos;
        else if (right == rpos) --lpos;
        else if (heights[lpos - 1] <= heights[rpos + 1]) ++rpos;
        else --lpos;
    }
    return ans;
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> heights[i];
        }

        cout << solve(1, n) << '\n';
    }
}