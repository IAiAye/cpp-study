#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n;
char star[3073][6144];

void Draw(int y, int x)
{
    star[y][x] = '*';
    star[y + 1][x - 1] = '*';
    star[y + 1][x + 1] = '*';
    star[y + 2][x - 2] = '*';
    star[y + 2][x - 1] = '*';
    star[y + 2][x] = '*';
    star[y + 2][x + 1] = '*';
    star[y + 2][x + 2] = '*';
}
// 삼각형의 위 꼭짓점의 좌표
void Tri(int size, int y, int x)
{
    if (size == 3)
    {
        Draw(y, x);
        return;
    }

    Tri(size / 2, y, x);
    Tri(size / 2, y + size / 2, x - size / 2);
    Tri(size / 2, y + size / 2, x + size / 2);
}

void Input()
{
    cin >> n;
}

void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            star[i][j] = ' ';
        }
    }

    Tri(n, 1, n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            cout << star[i][j];
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