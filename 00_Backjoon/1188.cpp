#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, m;

int gcd(int a, int b)
{
    while (b > 0)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}

void Input()
{
    cin >> n >> m;
}

void Solution()
{
    cout << m - gcd(n, m) << '\n';
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