#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int g;
int square[50001];

void Input()
{
    cin >> g;
}

void Solution()
{
    int past = 1;
    int curr = 2;

    vector<int> ans;

    while ((past < curr) && (curr <= (g + 1) / 2))
    {
        int temp = curr * curr - past * past;
        if (temp == g)
        {
            ans.push_back(curr);
            curr++;
        }
        else if (temp < g)
            curr++;
        else
            past++;
    }
    if (ans.empty())
        cout << -1 << '\n';
    else
    {
        for (auto curr : ans)
            cout << curr << '\n';
    }
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