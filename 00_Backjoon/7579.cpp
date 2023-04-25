#include <iostream>
#include <algorithm>
using namespace std;

int memories[101];
int costs[101];
// a까지의 메모리를 지웠을때 b만큼의 비용이 든다고 할때 생기는 메모리
int dp[101][10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> memories[i];
    }
    
    int costs_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> costs[i];
        costs_sum += costs[i];
    }
    
    // 하나씩 더해가며 그 비용에 나올 수 있는 최대한의 메모리를 계산한다.
    // 이때 메모리가 목표 메모리보다 넘는다면, 그 비용을 출력하고 종료한다.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= costs_sum; j++)
        {
            if (j - costs[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - costs[i]] + memories[i]);
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
        }
    }
    for (int i = 0; i <= costs_sum; i++)
    {
        if (dp[n][i] >= m)
        {
            cout << i << '\n';
            break;
        }
    }
    
    return 0;
}