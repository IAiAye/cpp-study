#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int a, b;

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
    cin >> a >> b;
}

void Solution()
{
    int GCD = gcd(a, b);
    cout << GCD << '\n' << a * b / GCD << '\n';
    
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