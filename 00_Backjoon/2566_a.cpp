#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[9][9];
int maxValue = -1;
int maxY = -1;
int maxX = -1;

void Input()
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            cin >> arr[y][x];
            if (maxValue < arr[y][x])
            {
                maxValue = arr[y][x];
                maxY = y;
                maxX = x;
            }
        }
    }
}

void Solution()
{
    cout << maxValue << '\n' << maxY + 1 << ' ' << maxX + 1 << '\n';
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