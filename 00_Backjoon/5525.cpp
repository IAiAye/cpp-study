#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
using namespace std;

string str;
int n, m;

void Input()
{
    cin >> n >> m;
    cin >> str;
}

void Solution()
{
    int ans = 0;
    for (int i = 0; i <= m - (2 * n + 1); i++)
    {
        int k = 0;
        if (str[i] == 'O')
            continue;

        while (str[i + 1] == 'O' && str[i + 2] =='I')
        {
            k++;
            if (k == n)
            {
                k--;
                ans++;
            }
            i += 2;
        }
        
        k = 0;
    }
    cout << ans << '\n';
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