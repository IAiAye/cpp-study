#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int a, b;

void Input()
{
    cin >> a >> b;
}

void Solution()
{
    cout << a + b << '\n';
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