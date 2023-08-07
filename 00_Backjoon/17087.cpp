#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, s;

int gcd(int a, int b)
{
    int temp;
    while (b > 0)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}


void Input()
{
    cin >> n >> s;
}

void Solution()
{
    int a;
    cin >> a;
    int GCD = abs(a - s);
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        GCD = gcd(GCD, abs(a - s));
    }
    cout << GCD << '\n';
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