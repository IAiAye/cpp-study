#include <iostream>

typedef long long ll; // ll is a shorthand for long long

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

ll phi(ll n) {
    ll result = n; // Initialize result as n

    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}

ll CountCoprimeOrGCD2(ll n) {
    ll phi_n = phi(n);
    ll gcd2Count = 0;

    for (ll k = 1; k <= n - 1; ++k) {
        if (gcd(n, k) == 2) { // Using the locally defined gcd function
            gcd2Count++;
        }
    }

    ll result = phi_n + gcd2Count;

    return result;
}

int main() {
    ll n;
    std::cout << "Enter a value for n: ";
    std::cin >> n;

    ll result = CountCoprimeOrGCD2(n);
    std::cout << "Number of k's satisfying the condition: " << result << std::endl;

    return 0;
}
