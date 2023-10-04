#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
using namespace std;

int n, m;
map<int, int> nums;

void dfs(int cnt, vector<int> arr)
{
    if (cnt == m)
    {
        for (int num : arr)
            cout << num << ' ';
        cout << '\n';
        return;
    }

    for (auto iter : nums)
    {
        if (iter.second  > 0)
        {
            arr.push_back(iter.first);
            nums[iter.first]--;
            dfs(cnt + 1, arr);

            arr.pop_back();
            nums[iter.first]++;
        }
    }
}

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        
        int num;
        cin >> num;
        
        if (nums.find(num) == nums.end())
            nums[num] = 1;
        else
            nums[num]++;
    }
}

void Solution()
{
    vector<int> arr;
    dfs(0, arr);
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