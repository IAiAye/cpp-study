#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

#define INF 2000000000

vector<pair <ll, ll>> init(int& n, int& S, vector<int>& arr)
{
    vector<pair <ll, ll>> tree;

    while(S < n)
        S <<= 1;
    tree.resize(S * 2, {INF, 0});

    for (int i = 0; i < n; i++)
    {
        tree[S + i].first = arr[i];
        tree[S + i].second = arr[i];
    }
    
    int SS = S;
    while (SS >>= 1)
    {
        for (int i = 0; i < SS; i++)
        {
            int j = SS + i;
            tree[j].first = min(tree[j * 2].first, tree[j * 2 + 1].first);
            tree[j].second = max(tree[j * 2].second, tree[j * 2 + 1].second);
        }
    }
    return tree;
}

ll min_query(int left, int right, int start, int end, int idx, vector<pair <ll, ll>>& tree)
{
    if (right < start || end < left)
        return INF;
    if (left <= start && end <= right)
        return tree[idx].first;

    int mid = (start + end) / 2;
    return min(min_query(left, right, start, mid, idx * 2, tree), min_query(left, right, mid + 1, end, idx * 2 + 1, tree));
}

ll max_query(int left, int right, int start, int end, int idx, vector<pair <ll, ll>>& tree)
{
    if (right < start || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[idx].second;

    int mid = (start + end) / 2;
    return max(max_query(left, right, start, mid, idx * 2, tree), max_query(left, right, mid + 1, end, idx * 2 + 1, tree));
}

// void update(int idx, int val, int S, vector<ll>& tree)
// {
//     idx += S;
//     tree[idx] = val;
//     while (idx >>= 1)
//         tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    int S = 1;

    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // 최소값 최대값 순으로 들고 있다.
    vector<pair <ll, ll>> tree = init(N, S, arr);
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << min_query(a, b, 0, S - 1, 1, tree) << '\n';
    }

    return 0;
}