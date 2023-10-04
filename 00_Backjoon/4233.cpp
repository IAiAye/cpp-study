#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;

ll a, p;

bool check_prime(ll num)
{ 
    //소수 최적화(루트 num까지 확인) 
    
    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

ll Power(ll a, ll n)
{
    if (n == 0)
        return 1;
    
    ll tmp = Power(a, n / 2);
    if (n & 1)
        return ((((tmp % p) * (tmp % p)) % p) * (a % p)) % p;
    else
        return ((tmp % p) * (tmp % p)) % p;
}

void Input()
{

}

void Solution()
{

    while (true)
    {
        cin >> p >> a;
        if (a == 0 && p == 0)
            break;
        if (!check_prime(p) && Power(a, p) == a)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
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