#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int tc;
int n;
int S = 1;
vector<ll> seg;
vector<ll> arr;

bool cmp1(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
bool cmp2(int a, int b)
{
    return a > b;
}



void init(int n)
{
    while (S < n)
        S <<= 1;
    seg = vector<ll>(2 * S);
    
    // for (int i = 0; i < n; i++)
    //     seg[S + i] = arr[i];
    
    // int SS = S;
    // while (SS /= 2)
    // {
    //     for (int i = 0; i < SS; i++)
    //     {
    //         int j = SS + i;
    //         seg[j] = seg[j * 2] + seg[j * 2 + 1];
    //     }
    // }
}

// l, r 쿼리로 주어지는 구간
// [s, e)는 idx번 segment가 담당하는 구간 (반열림 구간)
ll query(int left, int right, int start, int end, int idx)
{
    if (left <= start && end <= right)
        return seg[idx];
    if (end < left || right < start)
        return 0;
    int mid = (start + end) / 2;
    return query(left, right, start, mid, idx * 2) + query(left, right, mid + 1, end, idx * 2 + 1);
}
// S는 원래 배열의 size
void update(int idx)
{
    idx += S;
    seg[idx]++;
    while (idx /= 2)
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

void Input()
{
    cin >> tc;
}

void Solution()
{
    while (tc--)
    {
        int n;
        cin >> n;
        vector<pair <int, int>> plane;
        vector<int> v_y;
        init(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            plane.push_back({x, y});
            v_y.push_back(y);
        }
        // x가 작고, y가 큰 순대로 정렬
        sort(plane.begin(), plane.end(), cmp1);

        // y가 큰대로 정렬
        sort(v_y.begin(), v_y.end(), cmp2);

        ll ret = 0;

        for (int i = 0; i < n; i++)
        {
            int x = plane[i].first;
            int y = plane[i].second;

            int index = upper_bound(v_y.begin(), v_y.end(), y, cmp2) - v_y.begin() - 1;

            ret += query(0, index, 0, S - 1, 1);
            
            cout << x << ' ' << y << ' ' << index << ' ' << ret << '\n';
            update(index);
        }
        cout << ret << '\n';

        S = 1;
        seg.clear();
    }
    
    
    init(n);

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