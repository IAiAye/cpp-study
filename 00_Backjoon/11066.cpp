#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

//각 파일의 크기
int file[501];
// i번째까지의 파일의 누적합
int sum[501];
// i~j까지 합치는 비용
int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, k;
    cin >> t;
    while(t--)
    {
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> file[i];
            sum[i] = sum[i - 1] + file[i];
        }
        // i is gap
        for (int i = 1; i < k; i++)
        {
            // j is start idx
            for (int j = 1; j <= k - i; j++)
            {
                dp[j][i + j] = INF;
                // m is middle idx
                for (int m = j; m < i + j; m++)
                {
                    // dp[j][i + j]를 갱신해주면서 최소값을 찾아준다.
                    // j ~ m, m + 1 ~ i + j 의 합치는 비용과 j ~ i + j 까지의 누적합을 더해준다.
                    dp[j][i + j] = min(dp[j][i + j], dp[j][m] + dp[m + 1][i + j] + sum[i + j] - sum[j - 1]);
                }
            }
        }
        cout << dp[1][k] << '\n';
    }

    return 0;
}
