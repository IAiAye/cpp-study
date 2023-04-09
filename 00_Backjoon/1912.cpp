#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> cum_sum(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i == 0) {
            cum_sum[i] = arr[i];
        } else {
            cum_sum[i] = cum_sum[i-1] + arr[i];
        }
    }

    int max_sum = arr[0];
    int min_cum_sum = 0;
    for (int i = 0; i < n; i++) {
        max_sum = max(max_sum, cum_sum[i] - min_cum_sum); // 누적합 중에서 차이가 가장 큰 것이 부분합의 최대라고 할 수 있다.
        min_cum_sum = min(min_cum_sum, cum_sum[i]); // 따라서 i번째까지의 부분합중 최대값을 계속 반환한다.
    }

    cout << max_sum << '\n';

    return 0;
}
