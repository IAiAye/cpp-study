#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int n;
int honey[100001];
int psum[100001];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> honey[i];
        psum[i] = psum[i - 1] + honey[i];
    }
}

void Solution()
{
    int ans = 0;
    // 벌 - 꿀통 - 벌
    for (int i = 2; i <= n - 1; i++)
        ans = max(ans, (psum[i] - honey[1]) + (psum[n - 1] - psum[i] + honey[i]));
    
    // 꿀통 - 벌 - 벌
    for (int i = 2; i <= n - 1; i++)
        ans = max(ans, (psum[i] - honey[i]) + (psum[n - 1] - honey[i]));

    // 벌 - 벌 - 꿀통
    for (int i = 2; i <= n - 1; i++)
        ans = max(ans, (psum[n] - honey[1] - honey[i]) + (psum[n] - psum[i]));
    
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