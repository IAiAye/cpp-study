#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100010

int n, s;
int arr[MAX];

void Input()
{
    std::cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void Solution()
{
    int start = 0;
    int end = 0;

    int ans = n + 1;

    // 0번 인덱스부터 시작
    int sum = arr[0];
    while (end != n)
    {
        if (sum >= s)
        {
            // 최소값으로 갱신
            ans = min(end - start + 1, ans);

            // 왼쪽에서 빼고 당겨준다.
            sum -= arr[start];
            start++;
        }
        else 
        {
            // 오른쪽으로 늘려주고 더한다.
            end++;
            sum += arr[end];
        }
    }

    // 합이 불가능할 경우
    if (ans == n + 1) ans = 0;
    std::cout << ans << '\n';
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