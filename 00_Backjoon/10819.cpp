#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int n;
vector<int> v;

void Input()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
}

void Solution()
{
    sort(v.begin(), v.end());
    
    int MAX = 0;
    do
    {
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += abs(v[i] - v[i + 1]);
        MAX = max(MAX, sum);
    } while (next_permutation(v.begin(), v.end()));

    cout << MAX << '\n';
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