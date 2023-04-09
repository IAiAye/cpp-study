#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
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
        max_sum = max(max_sum, cum_sum[i] - min_cum_sum);
        min_cum_sum = min(min_cum_sum, cum_sum[i]);
    }

    cout << max_sum << endl;

    return 0;
}
