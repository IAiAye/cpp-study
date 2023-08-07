#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;

string str1, str2, str3;
int dp[101][101][101];

void Input()
{
    cin >> str1 >> str2 >> str3;
    str1 = ' ' + str1;
    str2 = ' ' + str2;
    str3 = ' ' + str3;
}

void Solution()
{
    int size1 = str1.size();
    int size2 = str2.size();
    int size3 = str3.size();

    for (int i = 1; i < size1; i++)
    {
        for (int j = 1; j < size2; j++)
        {
            for (int k = 1; k < size3; k++)
            {
                if (str1[i] == str2[j] && str2[j] == str3[k])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
            }
        }
    }
    cout << dp[size1 - 1][size2 - 1][size3 - 1] << '\n';
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