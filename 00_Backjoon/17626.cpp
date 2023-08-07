#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int dp[50001];

void Input()
{
    cin >> n;
}

void Solution()
{
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int s = static_cast<int>(sqrt(i));
        int min = 4;

        for (int j = 1; j <= s; j++)
        {
            if (dp[i - j * j] < min)
                min = dp[i - j * j];
        }
        
        dp[i] = min + 1;
    }
    cout << dp[n] << '\n';
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