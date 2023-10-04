#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
using namespace std;

string str;
int tc;
int m, n, x, y;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void Input()
{
    cin >> tc;
}

void Solution()
{
    while (tc--)
    {
        cin >> m >> n >> x >> y;
        if (x == y)
        {
            cout << x << '\n';
            continue;
        }
        int LCM = lcm(m, n);
        
        int i = x;
        bool flag = false;
        while (i <= LCM)
        {
            if (i % n == (y == n ? 0 : y))
            {
                flag = true;
                cout << i << '\n';
                break;
            }
            i += m;
        }

        if (!flag)
            cout << -1 << '\n';
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