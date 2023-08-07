#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define MAX 250001
bool isPrime[MAX];
int cnt[MAX];

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
            cnt[i]++;
            int j = 2;
            while (i * j <= MAX)
            {
                isPrime[i * j] = false;
                j++;
            }
        }
        cnt[i] += cnt[i - 1];
    }
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        
        cout << cnt[2 * n] - cnt[n] << '\n';
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