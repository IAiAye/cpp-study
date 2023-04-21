#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
long long heights[100002];

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
        heights[n + 1] = -1;
        stack <long long> s;

        s.push(0);
        long long ans = 0;
        // 스택, 시간 복잡도 O(N)
        for (int right = 1; right <= n + 1; right++)
        {
            // 다음 막대가 스택의 최상단 막대보다 작을 경우 (right)가 되고 넓이 계산 시작
            while (s.size() > 1 && heights[right] < heights[s.top()])
            {
                int mid = s.top();
                s.pop();
                // 높이가 증가하는대로 스택이 구성되있으므로 반드시 그 이전 스택이 left가 된다.
                int left = s.top();
                ans = max(ans, (right - left - 1) * heights[mid]);
            }
            s.push(right);
        }
        cout << ans << '\n';
    }
}
/*
우리는 특정 높이 막대에서 가장 넓은 직사각형을 구하려 한다.
그러기 위해선,
한 특정막대에서 왼쪽에 있으면서 높이가 낮은 것 중 가장 오른쪽에 있는 것 (left)
한 특정막대에서 오른쪽에 있으면서 높이가 낮은 것 중 가장 왼쪽에 있는 것 (right)
특정막대의 높이 -> heights[mid]
*/