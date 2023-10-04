#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

#define MAX 1001

int t, n;

void Input()
{
    cin >> t;
}

void Solution()
{
    while (t--)
    {
        cin >> n;
        vector<int> arr(n + 1, 0);
        vector<int> dp(n + 1, 0);


        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        int ans = -1001;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(0, dp[i - 1]) + arr[i];
            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
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