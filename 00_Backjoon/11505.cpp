#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

#define MOD 1000000007

vector<ll> init(int& n, int& S, vector<int>& arr)
{
    vector<ll> tree;

    while(S < n)
        S <<= 1;
    tree.resize(S * 2, 1);

    for (int i = 0; i < n; i++)
        tree[S + i] = arr[i];
    
    int SS = S;
    while (SS >>= 1)
    {
        for (int i = 0; i < SS; i++)
        {
            int j = SS + i;
            tree[j] = (tree[j * 2] * tree[j * 2 + 1]) % MOD;
        }
    }
    return tree;
}

ll query(int left, int right, int start, int end, int idx, vector<ll>& tree)
{
    if (right < start || end < left)
        return 1;
    if (left <= start && end <= right)
        return tree[idx] % MOD;

    int mid = (start + end) / 2;
    return (query(left, right, start, mid, idx * 2, tree) * query(left, right, mid + 1, end, idx * 2 + 1, tree)) % MOD;
}

void update(int idx, int val, int S, vector<ll>& tree)
{
    idx += S;
    tree[idx] = val;
    while (idx >>= 1)
        tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M, K, Q;
    int S = 1;

    cin >> N >> M >> K;
    Q = M + K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<ll> tree = init(N, S, arr);
    while (Q--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        a--, b--;
        if (op == 1)
            update(a, b + 1, S, tree);
        else
            cout << query(a, b, 0, S - 1, 1, tree) << '\n';
    }

    return 0;
}