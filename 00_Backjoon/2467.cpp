#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n;
vector<int> sol;

void Input()
{
    cin >> n;
    sol.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sol[i];
    }
}

void Solution()
{
    sort(sol.begin(), sol.end());
    pair<int, int> ans;
    int sum = 2000000000;

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int tmp = sol[left] + sol[right];
        if (abs(tmp) < sum)
        {
            ans.first = sol[left];
            ans.second = sol[right];
            sum = abs(tmp);
        }

        if (tmp > 0)
            right--;
        else
            left++;
    }
    cout << ans.first << ' ' << ans.second << '\n';
    
    
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