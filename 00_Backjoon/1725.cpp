#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

long long heights[100002];
stack <long long> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long area = 0;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> heights[i];
    }
    // 스택에는 높이가 큰 순대로의 인덱스를 추가해준다.
    // 인덱스 0일때는 항상 바닥이므로 항상 다음 수가 크다.
    s.push(0);

    for (int right = 1; right <= n + 1; right++)
    {
        // 다음 직사각형이 스택의 가장 높은 직사각형보다 작을때. 오작수 발견
        while(s.size() > 1 && heights[right] < heights[s.top()])
        {
            int mid = s.top();
            s.pop();
            // 크기가 큰 순으로 넣기때문에 스택 하나전에 있는 것은 항상 왼작수다.
            int left = s.top();
            area = max(area, (right - left - 1) * heights[mid]);
        }
        s.push(right);
    }
    cout << area;
    
    return 0;
}