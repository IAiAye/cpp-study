#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

vector<ll> init(int& n, int& S, vector<ll>& arr)
{

    while(S < n)
        S <<= 1;
    vector<ll> tree(S * 2, 0);

    for (int i = 0; i < n; i++)
        tree[S + i] = arr[i];
    
    int SS = S;
    while (SS >>= 1)
    {
        for (int i = 0; i < SS; i++)
        {
            int j = SS + i;
            tree[j] = tree[j * 2] + tree[j * 2 + 1];
        }
    }
    return tree;
}

void update_lazy(int idx, int start, int end, vector<ll>& tree, vector<ll>& lazy)
{
    if(lazy[idx] != 0)
    {
        tree[idx] += lazy[idx] * (ll)(end - start + 1);

        if (start != end)
        {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update(int left, int right, int start, int end, ll val, int idx, vector<ll>& tree, vector<ll>& lazy)
{
    update_lazy(idx, start, end, tree, lazy);
    if (right < start || end < left)
        return;

    if (left <= start && end <= right)
    {
        tree[idx] += (ll)(end - start + 1) * val;
        if (start != end)
        {
            lazy[idx * 2] += val;
            lazy[idx * 2 + 1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(left, right, start, mid, val, idx * 2, tree, lazy);
    update(left, right, mid + 1, end, val, idx * 2 + 1, tree, lazy);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

ll query(int left, int right, int start, int end, int idx, vector<ll>& tree, vector<ll>& lazy)
{
    update_lazy(idx, start, end, tree, lazy);
    if (right < start || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[idx];

    int mid = (start + end) / 2;
    return query(left, right, start, mid, idx * 2, tree, lazy) + query(left, right, mid + 1, end, idx * 2 + 1, tree, lazy);
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, Q, M, K;
    int S = 1;

    cin >> N >> M >> K;
    Q = M + K;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<ll> tree = init(N, S, arr);
    vector<ll> lazy(S * 2, 0);
    while (Q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ll b, c, d;
            cin >> b >> c >> d;
            update(b - 1, c - 1, 0, S - 1, d, 1, tree, lazy);
        }
        else
        {
            ll b, c;
            cin >> b >> c;
            cout << query(b - 1, c - 1, 0, S - 1, 1, tree, lazy) << '\n';
        }
    }

    return 0;
}