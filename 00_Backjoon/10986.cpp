#include <iostream>
using namespace std;

#define MAX 1001

long long mod[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    // (psum[j] - psum[i]) % m = 0 이면,
    // psum[j] % m == psum[i] % m 이어야 한다.
    // 즉, 나머지가 같은 것끼리 조합의 개수를 구하면 된다.

    // psum[j] % m = 0, 즉 연속합 자체가 나눠떨어질때도 고려해야한다.
    mod[0] = 1;
    long long tmp;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum = ( sum + tmp ) % m;
        mod[sum]++;
    }
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += mod[i] * ( mod[i] - 1 ) / 2;
    }
    
    cout << ans << '\n';
    return 0;
}
