#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
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
    vector<int> vA;
    vector<int> vB;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            vA.push_back(psumA[j] - psumA[i]);
        }
    }
    for (int i = 0; i <= m - 1; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            vB.push_back(psumB[j] - psumB[i]);
        }
    }
    sort(vA.begin(), vA.end());
    sort(vB.begin(), vB.end());

    int aSize = vA.size();
    int bSize = vB.size();

    int pA = 0;
    int pB = bSize - 1;

    ll ans = 0;


    // 1 50 100
    // 1 200


    while (pA < aSize && pB >= 0)
    {
        int sum = vA[pA] + vB[pB];
        if (sum == t)
        {
            ll cnt1 = 1;
            ll cnt2 = 1;

            while (pA + 1 < aSize && vA[pA] == vA[pA + 1])
            {
                pA++;
                cnt1++;
            }
            while (pB - 1 >= 0 && vB[pB] == vB[pB - 1])
            {
                pB--;
                cnt2++;
            }
            ans += cnt1 * cnt2;
            pA++;
        }
        else if (sum < t)
        {
            pA++;
        }
        else
        {
            pB--;
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