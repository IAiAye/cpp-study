#include <iostream>
using namespace std;

long long a, b, c;
int cnt;

long long pow(long long x, long long n) {
    if (n == 0) cnt++; return 1;
    if (n == 1) cnt++; return x % c;

    long long half = pow(x, n / 2);
    long long result = (half * half) % c;

    if (n % 2 == 1) {
        result = (result * x) % c;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    cout << pow(a, b) << '\n';
    cout << cnt << '\n';

    return 0;
}
