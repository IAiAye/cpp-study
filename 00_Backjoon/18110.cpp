#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector <int> diff;

void Input()
{
    cin >> n;
    diff.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> diff[i];
    }
}

void Solution()
{
    if (n == 0) 
    {
        cout << 0 << '\n';
        return;
    }
    sort(diff.begin(), diff.end());
    int del = round(n * 0.15);
    double sum = 0;
    for (int i = del; i < n - del; i++)
    {
        sum += diff[i];
    }
    cout << (int)round(sum / (n - 2 * del)) << '\n';
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
