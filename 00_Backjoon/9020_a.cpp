#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define MAX 10001
bool isPrime[MAX];

void Input()
{
}

void Solution()
{
    for (int i = 2; i <= MAX; i++)
        isPrime[i] = true;
    
    for (int i = 2; i <= MAX; i++)
    {
        if (isPrime[i])
        {
            int j = 2;
            while (i * j <= MAX)
            {
                isPrime[i * j] = false;
                j++;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = n / 2; i >= 2; i--)
        {
            if (isPrime[i] && isPrime[n - i])
            {
                cout << i << ' ' << n - i << '\n';
                break;
            }
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
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}