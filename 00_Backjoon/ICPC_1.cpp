#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair <ll, ll>> ssk(n);
    for (int i = 0; i < n; i++)
        cin >> ssk[i].first;
    for (int i = 0; i < n; i++)
        cin >> ssk[i].second;
    
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        double k;
        cin >> k;
        ll k_ = k * 10;
        if (k_ >= 10)
            ans += ssk[i].first * k_ / 10 - ssk[i].second;
        else
            ans += ssk[i].first - ssk[i].second * k_ / 10;
        // ans += max(ssk[i].first * k - ssk[i].second, ssk[i].first - ssk[i].second * k);
    }
    cout << ans << '\n';

    
    return 0;
}