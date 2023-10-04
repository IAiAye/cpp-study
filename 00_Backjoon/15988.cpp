#include <iostream>
using namespace std;
using ll = long long;

#define MAX 1000001

const ll MOD = 1e9 + 9;
int t, n;
ll dp[MAX];


void Input()
{
    cin >> t;
}

void Solution()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < MAX; i++)
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % MOD;
    
    while (t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
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