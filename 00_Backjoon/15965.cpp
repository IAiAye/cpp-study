#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define MAX 7500000
bool isPrime[MAX];
int k;

void Input()
{
    cin >> k;
}

void Solution()
{
    for (int i = 2; i < MAX; i++)
        isPrime[i] = true;
    
    int cnt = 0;

    for (int i = 2; i < MAX; i++)
    {
        if (isPrime[i])
        {
            cnt++;
            int j = 2;
            while (i * j < MAX)
            {
                isPrime[i * j] = false;
                j++;
            }
        }
        if (cnt == k)
        {
            cout << i << '\n';
            break;
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