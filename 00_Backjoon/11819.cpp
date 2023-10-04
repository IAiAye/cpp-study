#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
 
ll a, b, c;
ll Power(ll a, ll b)
{
    if (b == 0)
        return 1;
    
    __int128 tmp = Power(a, b / 2);
    if (b & 1)
        return ((((tmp % c) * (tmp % c)) % c) * (a % c)) % c;
    else
        return ((tmp % c) * (tmp % c)) % c;
}

void Input()
{
    cin >> a >> b >> c;
}

void Solution()
{
    cout << Power(a, b) << '\n';
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