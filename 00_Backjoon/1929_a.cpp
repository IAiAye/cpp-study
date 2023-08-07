#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define MAX 1000001
bool isPrime[MAX];
int m, n;

void Input()
{
    cin >> m >> n;
}

void Solution()
{
    for (int i = 2; i <= n; i++)
        isPrime[i] = true;
    
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            if (i >= m)
                cout << i << '\n';
            int j = 2;
            while (i * j <= n)
            {
                isPrime[i * j] = false;
                j++;
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