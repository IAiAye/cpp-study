#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int n, m;
int S = 1;
vector<pair<pair<int,int>,bool>> seg;
vector<int> arr;

void init(int n)
{
    while (S < n)
        S <<= 1;
    seg = vector<pair<pair<int,int>,bool>>(2 * S, {{10, 10}, 1});

    for (int i = 0; i < n; i++)
    {
        seg[S + i].first.first = arr[i];
        seg[S + i].first.second = arr[i];
        seg[S + i].second = 1;
    }
    
    int SS = S;
    while (SS /= 2)
    {
        for (int i = 0; i < SS; i++)
        {
            int j = SS + i;
            seg[j].first.first = seg[j * 2].first.first;
            seg[j].first.second = seg[j * 2 + 1].first.second;

            if (seg[j * 2].second == 1 && seg[j * 2 + 1].second == 1)
            {

                int gap = abs(seg[j * 2].first.second - seg[j * 2 + 1].first.first);
                if (gap == 2 || gap == 6)
                    seg[j].second = 0;
                else
                    seg[j].second = 1;
            }
            else
                seg[j].second = 0;
        }
    }
}

// l, r 쿼리로 주어지는 구간
// [b, e)는 idx번 segment가 담당하는 구간 (반열림 구간)
bool query(int l, int r, int b, int e, int idx)
{
    if (l <= b && e <= r)
        return seg[idx].second;
    if (e < l || r < b)
        return 1;
    int mid = (b + e) / 2;
    return (query(l, r, b, mid, idx * 2) && query(l, r, mid + 1, e, idx * 2 + 1));
}
// S는 원래 배열의 size
void update(int val, int idx)
{
    idx += S;
    seg[idx].first.first = val;
    seg[idx].first.second = val;

    while (idx /= 2)
    {
        seg[idx].first.first = seg[idx * 2].first.first;
        seg[idx].first.second = seg[idx * 2 + 1].first.second;

        if (seg[idx * 2].second == 1 && seg[idx * 2 + 1].second == 1)
        {

            int gap = abs(seg[idx * 2].first.second - seg[idx * 2 + 1].first.first);
            if (gap == 2 || gap == 6)
                seg[idx].second = 0;
            else
                seg[idx].second = 1;
        }
        else
            seg[idx].second = 0;
    }
}

void Input()
{
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void Solution()
{
    init(n);

    for (int i = 0; i < m; i++)
    {
        
        int op, b, c;
        cin >> op >> b >> c;
        if (op == 1)
            update(c, b - 1);
        else
            cout << query(b - 1, c - 1, 0, S - 1, 1) << '\n';

        // for (int i = 0; i < S; i++)
        // {
        //     cout << seg[i].second << ' ';
        // }
        // cout << '\n';
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