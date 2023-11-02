#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
using namespace std;
using ll = long long;

int t, n, m;
vector<int> arrA;
vector<int> arrB;
vector<int> psumA;
vector<int> psumB;

void Input()
{
    cin >> t >> n;

    arrA.resize(n + 1);
    psumA.resize(n + 1);
    psumA[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> arrA[i];
        psumA[i] = arrA[i] + psumA[i - 1];
    }

    cin >> m;
    
    arrB.resize(m + 1);
    psumB.resize(m + 1);
    psumB[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        cin >> arrB[i];
        psumB[i] = arrB[i] + psumB[i - 1];
    }
}

void Solution()
{
    map<int, int> mapA;

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            mapA[psumA[j] - psumA[i]]++;
        }
    }
    ll ans = 0;

    for (int i = 0; i <= m - 1; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            int sum = t - (psumB[j] - psumB[i]); 
            if (mapA.count(sum))
                ans += mapA[sum];
        }
    }

    cout << ans << '\n';
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