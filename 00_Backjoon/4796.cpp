#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;

int L, P, V;

void Input()
{

}

void Solution()
{
    int caseNum = 1;
    while (true)
    {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            break;

        int ans = V / P * L;
        if (V - (V / P * P) <= L)
            ans += V - (V / P * P);
        else
            ans += L;
        cout << "Case " << caseNum++ << ": " << ans << '\n';
    }
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