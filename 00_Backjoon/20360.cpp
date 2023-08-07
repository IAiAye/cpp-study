#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int n;
vector<int> digit;

void Input()
{
    cin >> n;
}

void Solution()
{
    int i = 0;
    while (n)
    {
        if (n & 1)
            digit.push_back(i);
        i++;
        n >>= 1;
    }
    
    int size = digit.size();
    for (auto x : digit)
        cout << x << ' ';
    cout << '\n';
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