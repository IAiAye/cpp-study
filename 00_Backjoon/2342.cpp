#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
using ll = long long;

vector<int> op;
int n;
int dp[5][5][100001];

int Check(int from, int to)
{
    if (from == 0)
        return 2;
    if (from == to)
        return 1;
    if (abs(from - to) == 2) 
        return 4;

    return 3;
}

int DP(int y, int x, int target)
{
    if (target == n)
        return 0;

    if (dp[y][x][target] != -1)
        return dp[y][x][target];

    // 왼발이 움직였을 때
    int left = DP(op[target], x, target + 1) + Check(y, op[target]);
    int right = DP(y, op[target], target + 1) + Check(x, op[target]);

    cout << y << ' ' << x << ' ' << target << '\n';
    return dp[y][x][target] = min(left, right);
}

void Input()
{
    while (true)
    {
        int num;
        cin >> num;
        if (num == 0)
            break;

        op.push_back(num);
        n++;
    }
}

void Solution()
{
    memset(dp, -1, sizeof(dp));
    cout << DP(0, 0, 0) << '\n';
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