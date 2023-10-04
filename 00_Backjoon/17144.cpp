#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int r, c, t;
// int space[51][51];
vector<int> tmp(51, 0);
vector<vector<int>> space(51, tmp);
vector<int> cleaner;

int add_y[4] = {1, 0, -1, 0};
int add_x[4] = {0, 1, 0, -1};

void Diffusion()
{
    vector<vector<int>> s(51, tmp);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (space[i][j] == -1)
            {
                s[i][j] = -1;
                continue;
            }
            else if (space[i][j] / 5 == 0)
            {
                s[i][j] += space[i][j];
                continue;
            }
            
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nexty = i + add_y[k];
                int nextx = j + add_x[k];
                
                if (1 <= nexty && nexty <= r && 1 <= nextx && nextx <= c)
                {
                    if (space[nexty][nextx] == -1)
                        continue;

                    cnt++;
                    s[nexty][nextx] += space[i][j] / 5;
                }
            }
            s[i][j] += space[i][j] - ((space[i][j] / 5) * cnt);
        }
    }
    space = s;
}

void Circulation()
{
    int up = cleaner[0];

    for (int i = up - 1; i > 1; i--)
        space[i][1] = space[i - 1][1];

    for (int i = 1; i < c; i++)
        space[1][i] = space[1][i + 1];

    for (int i = 1; i < up; i++)
        space[i][c] = space[i + 1][c];
    
    for (int i = c; i > 1; i--)
        space[up][i] = space[up][i - 1];
    
    space[up][2] = 0;

    int down = cleaner[1];

    for (int i = down + 1; i < r; i++)
        space[i][1] = space[i + 1][1];

    for (int i = 1; i < c; i++)
        space[r][i] = space[r][i + 1];

    for (int i = r; i > down; i--)
        space[i][c] = space[i - 1][c];
    
    for (int i = c; i > 1; i--)
        space[down][i] = space[down][i - 1];
    
    space[down][2] = 0;
}

void Input()
{
    cin >> r >> c >> t;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> space[i][j];
            if (space[i][j] == -1)
                cleaner.push_back(i);
        }
    }
}

void Solution()
{
    while (t--)
    {
        // cout << '\n';
        Diffusion();
        // for (int i = 1; i <= r; i++)
        // {
        //     for (int j = 1; j <= c; j++)
        //     {
        //         cout << space[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        Circulation();
        // for (int i = 1; i <= r; i++)
        // {
        //     for (int j = 1; j <= c; j++)
        //     {
        //         cout << space[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    int ans = 2;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            ans += space[i][j];
        }
    }
    cout << ans << '\n';
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