#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int n, s;
int arr[20];
int cnt;

void dfs(int idx, int sum)
{
    if (idx == n)
        return;

    if (sum + arr[idx] == s)
        cnt++;
    
    dfs(idx + 1, sum);

    dfs(idx + 1, sum + arr[idx]);
}

void Input()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void Solution()
{
    dfs(0, 0);
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