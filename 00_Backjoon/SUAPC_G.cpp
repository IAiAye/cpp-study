#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
using ll = long long;

int n;
int problem[5];
vector<priority_queue<int>> v(5);

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < 5; i++)
        cin >> problem[i];
    
    for (int i = 0; i < n; i++)
    {
        int k, t;
        cin >> k >> t;
        v[k - 1].push(-t);
    }
    int sum = -60;

    for (int i = 0; i < 5; i++)
    {
        sum += 60;
        int pre = -v[i].top();
        for (int j = 0; j < problem[i]; j++)
        {
            sum += (-v[i].top() - pre) - v[i].top();
            
            pre = -v[i].top();
            v[i].pop();
        }
    }
    cout << sum << '\n';


    return 0;
}