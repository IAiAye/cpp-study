#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int wine[10001];
    int sum[10001] = {0};
    
    for (int i = 1; i <= n; i++) // i 번째 잔.
    {
        cin >> wine[i];
    }
    sum[1] = wine[1];
    sum[2] = wine[1] + wine[2];

    for (int i = 3; i <= n; i++) 
    {
        sum[i] = max({sum[i - 1], sum[i - 2] + wine[i], sum[i - 3] + wine[i - 1] + wine[i]}); 
        // 그자리에서 안마시기 / 전전거 마시고 전에서 안마시기 / 전거 마시고 한칸 뛰고 마시기
    }
    
    cout << max(sum[n - 1], sum[n]) << '\n';

    return 0;
}