#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
using ll = long long;

ll c;

void Input()
{
    cin >> c;
}

void Solution()
{
    int n = 1;
    while (c != 1)
    {
        if ((c & 1) == 0)
            c /= 2;
        else
            c = c * 3 + 1;
        n++;
    }
    cout << n << '\n';
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