#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

#define MAX 1001

int t, n;
int dp[MAX];

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
        vector<int> psum(n + 1, 0);

        int sum = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
            psum[i] = sum;
        }
        
        int ans = -1001;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
                ans = max(ans, psum[j] - psum[i]);
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