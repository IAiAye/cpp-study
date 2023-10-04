#include <iostream>
#include <vector>

#define INF 2000000000

using namespace std;

typedef long long ll;

vector<ll> init_sum_tree(vector<int>& a, int n, int S) 
{
    vector<ll> tree(S * 2, 0);
    // Bottom layer
    for (int i = 0; i < n; i++)
        tree[S + i] = a[i];

    // Update parents
    int SS = S;
    while (SS /= 2) 
    {
        for (int i = SS; i < SS * 2; i++) 
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    return tree;
}

vector<int> init_min_tree(vector<int>& a, int n, int S) 
{
    vector<int> tree(S * 2, INF);
    // Bottom layer
    for (int i = 0; i < n; i++) 
        tree[S + i] = a[i];

    // Update parents
    int SS = S;
    while (SS /= 2) 
    {
        for (int i = SS; i < SS * 2; i++) 
            tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
    return tree;
}

void update(int idx, ll val, vector<ll>& sum_seg, vector<int>& min_seg, int S) 
{
    idx += S;
    sum_seg[idx] = val;
    min_seg[idx] = val;
    while (idx >>= 1) 
    {
        sum_seg[idx] = sum_seg[2 * idx] + sum_seg[2 * idx + 1];
        min_seg[idx] = min(min_seg[2 * idx], min_seg[2 * idx + 1]);
    }
}

ll query_sum_tree(vector<ll>& sum_seg, int l, int r, int S) 
{
    ll ret = 0;
    for (l += S, r += S; l <= r; l >>= 1, r >>= 1) 
    {
        if (l & 1) ret += sum_seg[l++];
        if (r & 1 ^ 1) ret += sum_seg[r--];
    }
    return ret;
}

pair<int, int> query_min_tree(vector<int>& tree, int i, int j, int S) 
{
    int here = S + i;
    int prev = here;
    int lo = -1;
    int hi = S;

    while (here /= 2) 
    {
        // j보다 작은 minimum을 발견했을 때
        // 왼쪽으로 내려간다.
        if (here * 2 != prev && tree[here * 2] < j && lo == -1) 
        {
            lo = here * 2;
            while (lo < S) 
            {
                if (tree[lo * 2 + 1] < j) 
                    lo = lo * 2 + 1;
                else 
                    lo *= 2;
            }
            lo -= S;
        }
        // 오른쪽으로 내려간다.
        if (here * 2 + 1 != prev && tree[here * 2 + 1] < j && hi == S) 
        {
            hi = here * 2 + 1;
            while (hi < S) 
            {
                if (tree[hi * 2] < j) 
                    hi *= 2;
                else 
                    hi = hi * 2 + 1;
            }
            hi -= S;
        }
        prev = here;
    }

    return { lo, hi };
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) 
        cin >> arr[i];

    int n = N;
    int S = 1;
    while (S < n)
        S <<= 1;

    vector<ll> sum_tree = init_sum_tree(arr, n, S);
    vector<int> min_tree = init_min_tree(arr, n, S);

    int M;
    cin >> M;
    for (int m = 0; m < M; m++) 
    {
        int op, i, j;
        cin >> op >> i >> j;
        i--;

        if (op == 1) 
            update(i, j, sum_tree, min_tree, S);
        else 
        {
            pair<int, int> result = query_min_tree(min_tree, i, j, S);
            cout << query_sum_tree(sum_tree, result.first + 1, result.second - 1, S) << "\n";
        }
    }


    return 0;
}