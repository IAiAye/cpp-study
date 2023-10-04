#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int n, m ,k;
int S = 1;
vector<ll> seg;
vector<ll> arr;

void init(int n)
{
    while (S < n)
        S <<= 1;
    seg = vector<ll>(2 * S);
    
    for (int i = 0; i < n; i++)
        seg[S + i] = arr[i];
    
    int SS = S;
    while (SS /= 2)
    {
        for (int i = 0; i < SS; i++)
        {
            int j = SS + i;
            seg[j] = seg[j * 2] + seg[j * 2 + 1];
        }
    }
}

// l, r 쿼리로 주어지는 구간
// [b, e)는 idx번 segment가 담당하는 구간 (반열림 구간)
ll query(int l, int r, int b, int e, int idx)
{
    if (l <= b && e <= r)
        return seg[idx];
    if (e <= l || r <= b)
        return 0;
    int mid = (b + e) / 2;
    return query(l, r, b, mid, idx * 2) + query(l, r, mid, e, idx * 2 + 1);
}
// S는 원래 배열의 size
void update(ll val, int idx)
{
    idx += S;
    seg[idx] = val;
    while (idx /= 2)
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

void Input()
{
    cin >> n >> m >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void Solution()
{
    init(n);

    for (int i = 0; i < m + k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(c, b - 1);
        else
            cout << query(b - 1, c, 0, S, 1) << '\n';
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