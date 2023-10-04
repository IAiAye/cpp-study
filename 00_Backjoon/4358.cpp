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

    map<string, int> m;
    double cnt = 0;
    string str;
    while (getline(cin, str))
    {
        cnt++;
        if (m.find(str) != m.end())
            m[str]++;
        else
            m[str] = 1;
    }
    cout << fixed;
    cout.precision(4);

    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << ' ' << (it->second) / cnt * 100 << '\n';
    
    return 0;
}