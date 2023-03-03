#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n; // n > m
    int sum = 0;
    int firstPrime = -1;

    for (int i = m; i <= n; i++)
    {
        bool isPrime = true;
        if (i == 1)
        {
            isPrime = false;
        }
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime == true)
        {
            sum += i;
            if (firstPrime == -1)
            {
                firstPrime = i;
            }
        }
    }
    if (sum != 0)
    {
        cout << sum << '\n' << firstPrime << '\n';
    } else cout << firstPrime << '\n';
}