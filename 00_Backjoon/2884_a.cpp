#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int h, m;

void Input()
{
    cin >> h >> m;
}

void Solution()
{
    m -= 45;
    if (m < 0)
    {
        m += 60;
        h--;
        if (h < 0)
            h += 24;
    }
    cout << h << ' ' << m << '\n';
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