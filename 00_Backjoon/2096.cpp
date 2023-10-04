#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <stack>
using namespace std;

int minDP[3];
int maxDP[3];
int arr[3];
int n;

void Input()
{
    cin >> n;
}

void Solution()
{
    cin >> arr[0] >> arr[1] >> arr[2];
    minDP[0] = arr[0];
    minDP[1] = arr[1];
    minDP[2] = arr[2];

    maxDP[0] = arr[0];
    maxDP[1] = arr[1];
    maxDP[2] = arr[2];
    for (int i = 2; i <= n; i++)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        int tmp0 = minDP[0];
        int tmp1 = minDP[1];
        int tmp2 = minDP[2];

        minDP[0] = min(tmp0, tmp1) + arr[0];
        minDP[1] = min(min(tmp0, tmp1), tmp2) + arr[1];
        minDP[2] = min(tmp1, tmp2) + arr[2];

        tmp0 = maxDP[0];
        tmp1 = maxDP[1];
        tmp2 = maxDP[2];

        maxDP[0] = max(tmp0, tmp1) + arr[0];
        maxDP[1] = max(max(tmp0, tmp1), tmp2) + arr[1];
        maxDP[2] = max(tmp1, tmp2) + arr[2];
    }
    cout << max(max(maxDP[0], maxDP[1]), maxDP[2]) << ' ' << min(min(minDP[0], minDP[1]), minDP[2]) << '\n';
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