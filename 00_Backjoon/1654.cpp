#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long wires[10001];
int k, n;
long long maxL;
long long maxW;

void find(long long left, long long right)
{
    // 왼쪽이 오른쪽보다 커지는 경우 종료
    if (left > right) return;
    
    long long mid = (left + right) / 2;
    long long sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += wires[i] / mid;
    }
    if (sum >= n) 
    {
        // 최대값을 저장해준다.
        maxL = max(maxL, mid);
        find(mid + 1, right);
    }
    else find(left, mid - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;
    for (int i = 1; i <= k; i++)
    {
        cin >> wires[i];
        maxW = max(maxW, wires[i]);
    }
    
    // 가장 긴 선을 잘라서만으로도 개수를 충족할수도 있으므로, 가장 긴선부터 탐색
    find(1, maxW);
    cout << maxL << '\n';

    // // 브루트 포스로 푼다하면
    // while(1)
    // {
    //     maxL++;
    //     int sum = 0;
    //     for (int i = 1; i <= k; i++)
    //     {
    //         sum += wires[i] / maxL;
    //     }
    //     if (sum < n) break;
    // }
    // cout << maxL - 1 << '\n';
}