#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m, b;
int minValue = 257, maxValue = -1;
int map[501][501];
int minTime = 500 * 500 * 256 * 2;
int height;

double avg;
void Input()
{
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            minValue = min(minValue, map[i][j]);
            maxValue = max(maxValue, map[i][j]);
            //avg += map[i][j];
        }
    }
    //avg = round(avg / (n * m));
}

void Solution()
{
    //int target = avg;
    for (int k = minValue; k <= maxValue; k++)
    {
        int block = b;
        int time = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int gap = k - map[i][j];
                // 1번 작업
                if (gap < 0)
                {
                    block += (-1 * gap);
                    time += (-2 * gap);
                }
                // 2번 작업
                else if (gap > 0)
                {
                    block -= gap;
                    time += gap;
                }
            }
        }
        if (block < 0)
        {
            continue;
        }
        if (minTime >= time)
        {
            minTime = time;
            height = k;
        }
    }
    cout << minTime << ' ' << height;
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
