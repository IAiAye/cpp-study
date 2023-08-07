#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

string str;

void Input()
{
    cin >> str;
}

void Solution()
{
    int left = 0;
    int right = str.size() - 1;

    while (left < right)
    {
        if (str[left++] != str[right--])
        {
            cout << 0 << '\n';
            return;
        }
    }
    cout << 1 << '\n';
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