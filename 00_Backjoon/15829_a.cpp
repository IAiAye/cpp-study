#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int l;
string str;

void Input()
{
    cin >> l;
    cin >> str;
}

void Solution()
{
    long long H = 0;
    long long r = 1;
    int M = 1234567891;
    for (int i = 0; i < l; i++)
    {
        int a = str[i] - 'a' + 1;
        H = (H + a * r) % M;
        r = (r * 31) % M;
    }
    cout << H << '\n';
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