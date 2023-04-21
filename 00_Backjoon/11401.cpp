#include <iostream>
using namespace std;

long long n, k;
long long p = 1000000007;

long long multi(int a, int n)
{
    if (n == 1)
    {
        return a % p;
    }
    long long tmp = multi(a, n / 2);
    tmp = tmp * tmp % p; // a^b = a^b/2 * a^b/2

    if (n % 2 == 1) return tmp * a % p; // b가 홀수일 경우, a를 한 번 더 곱해줌.
    else return tmp;   
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    long long n_fac = 1; // n! = A
    for (int i = 1; i <= n; i++)
    {
        n_fac *= i;
        n_fac %= p;
    }

    long long k_fac_n_k_fac = 1; // k!*(n-k)! = B
    for (int i = 1; i <= k; i++)
    {
        k_fac_n_k_fac *= i;
        k_fac_n_k_fac %= p;
    }
    for (int i = 1; i <= n - k; i++)
    {
        k_fac_n_k_fac *= i;
        k_fac_n_k_fac %= p;
    }
    // n! / ( k! * (n - k)! ) 의 mod p를 구하는 것이 목표.
    // 이때 B와 p은 서로소 이므로 B^p-1 = 1 (mod p) 이다.
    // 이를 위위 식에 곱해주면 A * B^p-2 = A / B (mod p) 가 된다.
    cout << ( n_fac * multi(k_fac_n_k_fac, p - 2) ) % p << '\n';

    return 0;
}