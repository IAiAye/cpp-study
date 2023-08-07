#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void Input()
{

}

void Solution()
{
    int n;
    while (cin >> n)
    {
        long long number = 1;
        int digit = 1;
        long long ten = 10;
        while (true)
        {
            if (number % n == 0)
                break;
            digit++;
            ten = ten % n;
            number = (number % n + ten) % n;
            ten = (ten * (10 % n)) % n;
        }
        cout << digit << '\n';
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