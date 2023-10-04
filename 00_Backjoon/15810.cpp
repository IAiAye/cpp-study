#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;

ll n, m;
vector<ll> times;
ll maxB;

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        times.push_back(b);
        maxB = max(maxB, b);
    }
}

void Solution()
{
    ll left = 1;
    ll right = ((m / n) + 1) * maxB;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += mid / times[i];
        
        if (sum >= m)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left << '\n';
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