#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    long long arr[101][10];
    long long sum[101] = { 0 };

    arr[1][0] = 0;
    for (int i = 1; i < 10; i++)
    {
        arr[1][i] = 1;
        sum[1] += 1;
    }
    
    for (int i = 2; i <= n; i++)
    {
        arr[i][0] = arr[i - 1][1] % 1000000000;
        sum[i] += arr[i][0];
        for (int j = 1; j < 9; j++)
        {
            arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000; // i 자리수의 j를 일의 자리로 갖는 계단 수
            sum[i] += arr[i][j];
        }
        arr[i][9] = arr[i - 1][8] % 1000000000;
        sum[i] += arr[i][9];
    }
    cout << sum[n] % 1000000000;

    return 0;
}