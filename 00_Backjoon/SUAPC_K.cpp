#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    ll X1 = 0;
    ll Y1 = 0;

    for (int i = 0; i < 4; i++)
    {
        ll x, y;
        cin >> x >> y;
        X1 += x;
        Y1 += y;
    }

    ll X2 = 0;
    ll Y2 = 0;

    for (int i = 0; i < 4; i++)
    {
        ll x, y;
        cin >> x >> y;
        X2 += x;
        Y2 += y;
    }
    ll Ygap = Y2 - Y1;
    ll Xgap = X2 - X1;


    // p가 정수
    if (Ygap % Xgap == 0)
        cout << Ygap / Xgap << ' ';
    else
    {
        bool isNegative = true;
        if (Ygap * Xgap > 0)
            isNegative = false;
        
        ll GCD = gcd(Ygap, Xgap);
        Ygap /= GCD;
        Xgap /= GCD;
        if (isNegative)
            cout << '-' << abs(Ygap) << '/' << abs(Xgap) << ' ';
        else
            cout << abs(Ygap) << '/' << abs(Xgap) << ' ';
    }

    ll qt = (Y1 * Xgap) - (X1 * Ygap);
    ll qb = (4 * Xgap);

    if (qt % qb == 0)
        cout << qt / qb << '\n';
    else
    {
        bool isNegative = true;
        if (qt * qb > 0)
            isNegative = false;

        ll GCD = gcd(qt, qb);
        qt /= GCD;
        qb /= GCD;
        if (isNegative)
            cout << '-' << abs(qt) << '/' << abs(qb) << '\n';
        else
            cout << abs(qt) << '/' << abs(qb) << '\n';
    }

    return 0;
}