#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

using int16 = __int16_t;
int16 arr[100][100];
int16 n, m;

void Input()
{
    cin >> n >> m;
    for (int16 y = 0; y < n; y++)
    {
        for (int16 x = 0; x < m; x++)
        {
            cin >> arr[y][x];
        }
    }
    for (int16 y = 0; y < n; y++)
    {
        for (int16 x = 0; x < m; x++)
        {
            int16 tmp;
            cin >> tmp;
            arr[y][x] += tmp;
        }
    }
}

void Solution()
{
    for (int16 y = 0; y < n; y++)
    {
        for (int16 x = 0; x < m; x++)
        {
            cout << arr[y][x] << ' ';
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