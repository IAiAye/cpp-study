#include <iostream>
using namespace std;

int t, n;
int fibo[41];

int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (fibo[n]) return fibo[n];

    fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fibo[n];
}

void Input()
{
    cin >> t;
}

void Solution()
{
    fibo[0] = 0;
    fibo[1] = 1;
    while (t--)
    {
        cin >> n;
        fibonacci(n);
        if (n == 0) cout << 1 << ' ' << 0 << '\n';
        else cout << fibo[n - 1] << ' ' << fibo[n] << '\n';    
    }
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}
