#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> prefix_sum(n + 1, 0); // 입력 배열의 누적 합 배열

    // 입력 배열의 누적 합 배열 계산
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        prefix_sum[i] = prefix_sum[i-1] + num;
    }

    // 구간 합 계산
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        cout << prefix_sum[end] - prefix_sum[start-1] << '\n';
    }

    return 0;
}
