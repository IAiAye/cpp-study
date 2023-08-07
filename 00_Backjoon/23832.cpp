#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
int phi[50001];

void Input()
{
    cin >> n;
}

void Solution()
{
    for (int i = 1; i <= n; i++)
        phi[i] = i;
    
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        if (phi[i] != i)
        {
            // cout << phi[i] << '\n';
            sum += phi[i];
            continue;
        }
        // 소수일 때
        int j = 1;
        while (i * j <= n)
        {
            phi[i * j] -= phi[i * j] / i;
            j++;
        }
        // cout << phi[i] << '\n';
        sum += phi[i];
    }
    cout << sum << '\n';
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