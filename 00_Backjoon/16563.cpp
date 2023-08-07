#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
#define MAX 5000001
int minFactor[MAX];

void Input()
{
    cin >> n;
}

void Solution()
{
    for (int i = 2; i < MAX; i++)
        minFactor[i] = i;
    
    for (int i = 2; i * i < MAX; i++)
    {
        // 소수라면,
        if (minFactor[i] == i)
        {
            int j = i;
            while (i * j < MAX)
            {
                if (minFactor[i * j] == i * j)
                    minFactor[i * j] = i;
                j++;
            }
        }
    }

    while (n--)
    {
        int num;
        cin >> num;
        while (num > 1)
        {
            cout << minFactor[num] << ' ';
            num /= minFactor[num];
        }
        cout << '\n';
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