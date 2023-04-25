#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// 추의 배열
int weights[31];
// i 번째 추까지 넣었을때 측정할 수 있는 무게라면 참, 아니라면 거짓 
bool dp[31][40001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int sum = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> weights[i];
        sum += weights[i];
        // 아무것도 안올렸을때 0kg도 측정이 가능하다.
        dp[i][0] = true;
    }
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // i번째 추를 놓지않고, j kg를 잴 수 있거나, 
            // j kg에서 i번째 추의 무게를 빼거나 더했을때 측정이 가능하다면 참
            dp[i][j] = (dp[i - 1][j] || dp[i - 1][abs(j - weights[i])] || dp[i - 1][j + weights[i]]);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= sum; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int t;
    cin >> t;

    string ans = "";
    while(t--)
    {
        int num;
        cin >> num;
        if (dp[n][num]) ans += "Y ";
        else ans += "N ";
    }
    cout << ans << '\n';
    return 0;
}