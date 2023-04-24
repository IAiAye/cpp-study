#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long ans;
vector <long long> heights;

void find(long long left, long long right)
{
    if (left > right) return;

    long long mid = (left + right) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (heights[i] > mid) sum += heights[i] - mid;
    }
    if (sum >= m) 
    {
        ans = max(ans, mid);
        find(mid + 1, right);
    }
    else find(left, mid - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    long long maxH = 0;
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        heights.push_back(tmp);
        maxH = max(maxH, tmp);
    }
    // 최고 높이의 나무부터 이진 탐색 시작
    find(1, maxH);
    cout << ans << '\n';
}