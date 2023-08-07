#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int dp[11][11];
int n, k;

int Combination(int n, int k)
{
    if (dp[n][k])
        return dp[n][k];
    
    if (n == k || k == 0)
    {
        dp[n][k] = 1;
        return 1;
    }
    
    dp[n][k] = Combination(n - 1, k) + Combination(n - 1, k - 1);
    return dp[n][k];
}

void Input()
{
    cin >> n >> k;
}

void Solution()
{
    cout << Combination(n, k) << '\n';
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