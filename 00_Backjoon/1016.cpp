#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
ll MIN, MAX;

void Input()
{
    cin >> MIN >> MAX;    
}

void Solution()
{
    int cnt = MAX - MIN + 1;
    vector<bool> visited(cnt, false);

    ll i = 2;
    while (i * i <= MAX)
    {
        ll Square = i * i;
        ll sNum = MIN / Square;
        if (MIN % Square != 0)
            sNum++;
        
        while (sNum * Square <= MAX)
        {
            if (!visited[sNum * Square - MIN])
            {
                visited[sNum * Square - MIN] = true;
                cnt--;
            }
            sNum++;
        }
        i++;       
    }
    

    cout << cnt << '\n';
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