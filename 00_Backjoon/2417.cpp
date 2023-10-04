#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ull = unsigned long long;

ull n;

void Input()
{
    cin >> n;
}

void Solution()
{
    if (n == 0)
    {
        cout << 0 << '\n';
        return;
    }
    ull left = 0;
    ull right = sqrt(n);
    while (left <= right)
    {
        ull mid = (left + right) / 2;
        if (mid * mid >= n)
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