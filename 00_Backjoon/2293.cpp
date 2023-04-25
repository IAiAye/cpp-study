#include <iostream>
using namespace std;

//동전의 종류
int coins[101];
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    // 0원을 만들 수 있는 방법은 1가지.
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
        for (int j = coins[i]; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    cout << dp[k] << '\n';
    return 0;
}