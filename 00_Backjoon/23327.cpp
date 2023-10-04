#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;


void Input()
{
}

void Solution()
{
    int n, q;
    
    cin >> n >> q;
    vector<ll> fun(n + 1, 0);
    vector<ll> psum(n + 1, 0);
    vector<ll>  triangle(n + 1, 0);
    

    for (int i = 1; i <= n; i++)
    {
        cin >> fun[i];
        psum[i] = psum[i - 1] + fun[i];
        // 1 ~ i 까지의 리그전의 재미
        triangle[i] = triangle[i - 1] + fun[i] * psum[i - 1];
    }
    
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        ll ans = triangle[r] - triangle[l] - psum[l - 1] * (psum[r] - psum[l]);

        cout << ans << '\n';
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