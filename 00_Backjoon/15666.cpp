#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <stack>
using namespace std;

int n, m;
int nums;
vector<int> arr;
set<int> s;

void dfs(int cnt, int idx, vector<int>& v)
{
    if (m == cnt)
    {
        for (int num : v)
            cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i < nums; i++)
    {
        v.push_back(arr[i]);
        dfs(cnt + 1, i, v);
        v.pop_back();
    }
}

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    for (auto iter = s.begin(); iter != s.end(); iter++)
    {
        nums++;
        arr.push_back(*iter);
    }
    
}

void Solution()
{
    vector<int> v;
    dfs(0, 0, v);
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