#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    map<int, int> um;

    for (int i = 0; i < a; i++)
    {
        int tmp;
        cin >> tmp;
        um[tmp] = 1;
    }
    for (int i = 0; i < b; i++)
    {
        int tmp;
        cin >> tmp;
        if (um.find(tmp) != um.end())
        {
            a--;
            um[tmp]++;
        }
    }
    cout << a << '\n';

    for (auto it = um.begin(); it != um.end(); it++)
    {
        if (it->second == 1)
            cout << it->first << ' ';
    }
    cout << '\n';

    return 0;
}