#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int n;

void Input()
{
    cin >> n;
}

void Solution()
{
    int cnt = 0;
    for (int b = 1; b < 500; b++)
    {
        for (int a = b + 1; a <= 500; a++)
        {
            if (a * a - b * b == n)
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
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