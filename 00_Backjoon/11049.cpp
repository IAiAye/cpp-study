#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int matrix[501][2];
// a ~ b까지 곱하는데 필요한 곱셈 연산의 최소값
int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1];
    }
    for (int gap = 1; gap < n; gap++)
    {
        // left bound : i
        for (int i = 1; i <= n - gap; i++)
        {
            // right bound : j
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int m = i; m < j; m++)
            {
                // i ~ j 까지의 행렬 곱의 최소값
                dp[i][j] = min( dp[i][j], dp[i][m] + dp[m + 1][j] + matrix[i][0] * matrix[m][1] * matrix[j][1] );
            }
        }
    }
    cout << dp[1][n] << '\n';

    return 0;
}
