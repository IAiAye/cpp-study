#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> prefix_sum(n + 1, 0); // 입력 배열의 누적 합 배열

    // 입력 배열의 누적 합 배열 계산
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        prefix_sum[i] = prefix_sum[i - 1] + num;
    }

    int num_max = -10000000;
    // 구간 합 계산
    for (int i = k; i <= n; i++)
    {
        num_max = max(num_max, prefix_sum[i] - prefix_sum[i - k]);    
    }

    cout << num_max;
    return 0;
}
