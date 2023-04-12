#include <iostream>
#include <algorithm>
using namespace std;

char board[2001][2001];
int BW[2001][2001];
int WB[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    int num_max = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
            if ((i + j) % 2 == 0)
            {
                if (board[i][j] == 'B')
                {
                    BW[i][j] = BW[i - 1][j] + BW[i][j - 1] + 1 - BW[i - 1][j - 1];
                    WB[i][j] = WB[i - 1][j] + WB[i][j - 1] - WB[i - 1][j - 1];
                }
                else
                {
                    BW[i][j] = BW[i - 1][j] + BW[i][j - 1] - BW[i - 1][j - 1];
                    WB[i][j] = WB[i - 1][j] + WB[i][j - 1] + 1 - WB[i - 1][j - 1];
                }
            }
            else
            {
                if (board[i][j] == 'W')
                {
                    BW[i][j] = BW[i - 1][j] + BW[i][j - 1] + 1 - BW[i - 1][j - 1];
                    WB[i][j] = WB[i - 1][j] + WB[i][j - 1] - WB[i - 1][j - 1];
                }
                else
                {
                    BW[i][j] = BW[i - 1][j] + BW[i][j - 1] - BW[i - 1][j - 1];
                    WB[i][j] = WB[i - 1][j] + WB[i][j - 1] + 1 - WB[i - 1][j - 1];
                }
            }
            if ((i - K >= 0) && (j - K) >= 0)
            {
                int num_BW = BW[i][j] - BW[i - K][j] - BW[i][j - K] + BW[i - K][j - K];
                int num_WB = WB[i][j] - WB[i - K][j] - WB[i][j - K] + WB[i - K][j - K];
                num_max = max(num_max, max(num_BW, num_WB));
            }
        }
    }

    cout << K * K - num_max << '\n';

    return 0;
}
