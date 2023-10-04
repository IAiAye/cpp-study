#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
using ll = long long;

int n, k;
vector<priority_queue<int>> v(12);

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int p, w;
        cin >> p >> w;
        v[p].push(w);
    }
    int sum = 0;
    while (k--)
    {
        sum = 0;
        for (int i = 1; i <= 11; i++)
        {
            if (v[i].empty())
                continue;
            
            if (v[i].top() != 1)
            {
                int tmp = v[i].top() - 1;
                v[i].pop();
                v[i].push(tmp);
            }
            sum += v[i].top();
        }
    }
    cout << sum << '\n';

    return 0;
}