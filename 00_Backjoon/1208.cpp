#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
using ll = long long;

int n, s;
int arr[40];
ll cnt;
unordered_map<int, int> m;

void leftDfs(int idx, int sum)
{
    if (idx == n / 2)
    {
        m[sum]++;
        return;
    }
    
    leftDfs(idx + 1, sum);
    leftDfs(idx + 1, sum + arr[idx]);
}

void rightDfs(int idx, int sum)
{
    if (idx == n)
    {
        if (m.find(s - sum) != m.end())
            cnt += m[s - sum];
        return;
    }

    rightDfs(idx + 1, sum);
    rightDfs(idx + 1, sum + arr[idx]);
}

void Input()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void Solution()
{
    leftDfs(0, 0);
    rightDfs(n / 2, 0);

    if (s == 0)
        cout << cnt - 1 << '\n';
    else
        cout << cnt << '\n';
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