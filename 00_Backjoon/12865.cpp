#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int DP[101][100001]; // 물건의 갯수, 가방의 무게, 가방의 총가치를 저장
int W[101];
int V[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> W[i] >> V[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j - W[i] >= 0) // 용량보다 작아야 들어갈 수 있다.
            {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
                // i 번째 물품을 안넣었을때의 가치와 i 번째 용량만큼의 공간을 비우고 가치를 더했을때.
            } else DP[i][j] = DP[i - 1][j];
            
        }
    }
    cout << DP[n][k];
    
    return 0;
}