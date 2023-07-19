#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

long long power(long long x, int n) 
{
    if (n == 0) 
    {
        return 1;
    }

    long long temp = power(x, n / 2);
    if (n % 2 == 0) 
    {
        return temp * temp;
    } 
    else 
    {
        if (n > 0) 
        {
            return x * temp * temp;
        } 
        else 
        {
            return (temp * temp) / x;
        }
    }
}


int t;
void Input()
{
    cin >> t;
}

void Solution()
{
    while(t--)
    {
        long long n;
        cin >> n;

        bool flag = false;
        for (long long k = 2; k * k < n; k++)
        {
            int a = 2;
            long long value = k + 1;

            while (true)
            {
                value += static_cast<long long>(power(k,a));

                if (n == value)
                {
                    flag = true;
                    break;
                }
                else if (n < value) break;
                a++;
            }
            if (flag) break;
        }
        if (flag)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
    
    return 0;
}