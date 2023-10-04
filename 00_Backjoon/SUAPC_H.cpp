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
ll length[100001];
ll psum[100001];
ll L;
int q;

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> length[i];
        psum[i] += psum[i - 1] + length[i];
    }
    cin >> L >> q;

    cout << fixed;
    cout.precision(2);

    while (q--)
    {
        int num;
        cin >> num;

        double ans = psum[num - 1] * 10 + length[num] * 10 / 2 - L * 10 / 2;

        if (psum[n] < L && ans >= 0)
            ans = 0;
        else if (ans <= 0)
            ans = 0;
        else if (ans + L * 10 > psum[n] * 10)
            ans = psum[n] * 10 - L * 10;
        
        ans /= 10;
        cout << ans << '\n';
    }
    
    return 0;
}