#include <iostream>
using namespace std;

int n;

void Input()
{
    cin >> n;
}

void Solution()
{
    // 5 1
    // 10 2
    // 15 3
    // 20 4
    // 25 5 6
    // 30 7
    // 35 8
    // 40 9 
    // 45 10
    // 50 11 12

    cout << n / 125 + n / 25 + n / 5 << '\n';
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
