#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int arr[500][500]; // i층 j번째
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {  // 맨 왼쪽인 경우
                arr[i][j] += arr[i-1][j];
            } else if (j == i) {  // 맨 오른쪽인 경우
                arr[i][j] += arr[i-1][j-1];
            } else {  // 가운데인 경우
                arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
            }
        }
    }
    
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        max_sum = max(max_sum, arr[n-1][i]);
    }
    cout << max_sum << '\n';

    return 0;
}
