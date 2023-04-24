#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
long long maxG;
long long ans;
long long minG = 1000000001;
vector <long long> pos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        pos.push_back(tmp);
    }
    sort(pos.begin(), pos.end());
    // O(N)
    for (int i = 0; i < n - 1; i++)
    {
        minG = min(minG, pos[i + 1] - pos[i]);
    }
    // 갭의 최소 구하기.
    long long left = minG;
    // 최대 갭은 수직선에서 처음과 끝이다.
    long long right = pos.back() - pos.front();
    
    // O(N log G)
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        int cnt = 1;
        long long installed = pos[0];
        // O(N)
        for (int i = 1; i < n; i++)
        {
            // mid의 갭 이상인 집에 설치함.
            if (pos[i] >= installed + mid)
            {
                cnt++;
                installed = pos[i];
            }
        }
        // O(log G)
        if (cnt < c) right = mid - 1;
        else if (cnt >= c) 
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
    }
    cout << ans << '\n';
}
/*
수직선을 c-1개로 나눴을때 최대가 될 수 있는 segment의 길이를 구하는 것
*/