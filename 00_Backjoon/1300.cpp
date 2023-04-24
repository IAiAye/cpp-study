#include <iostream>
#include <algorithm>
using namespace std;
long long n, k;

long long count(long long a)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        // a보다 작거나 같은 수의 갯수를 세준다.
        sum += min(a / i, n);
    }
    return sum;
}

int main()
{
    cin >> n >> k;
    k = min((long long)1000000000, k);

    // 모든 수의 범위
    long long left = 1;
    long long right = n * n;

    // O(2 log n)
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        // O(n)
        long long cnt = count(mid);

        // 카운트해준 것이 목표 넘버와 같거나 크다면, 범위를 왼쪽으로 줄여준다.
        if (cnt >= k) right = mid - 1;
        else if (cnt < k) left = mid + 1;
    }
    // left가 right보다 1 커지는 순간 루프 탈출
    cout << left << '\n';
    return 0;
}
