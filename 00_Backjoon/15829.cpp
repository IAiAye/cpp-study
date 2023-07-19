#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int L;
string str;

void Input()
{
    cin >> L;
    cin >> str;
}

void Solution()
{
    // 31 ^ 0
    long long r = 1;
    int M = 1234567891;

    long long H = 0;
    for (int i = 0; i < L; i++)
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
