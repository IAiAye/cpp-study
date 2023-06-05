#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <int> primes;

void Input()
{
    std::cin >> n;
}

void Prime()
{
    vector <bool> isPrime(n + 1, true);

    for (int i = 2; i * i <= n; i++)
    {
        if (!isPrime[i]) continue;
        // i의 배수 모두 제거
        for (int j = 2 * i; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i]) primes.push_back(i);
    }
}

void Solution()
{
    Prime();

    int cnt = 0;

    int start = 0;
    int end = 0;
    int sum = 0;

    // 소수가 없는 경우, n이 1일때
    if (primes.empty())
    {
        std::cout << 0 << '\n';
        return;
    }

    while (end <= primes.size())
    {
        if (sum < n)
        {
            sum += primes[end];
            end++;
        }
        else if (sum > n)
        {
            sum -= primes[start];
            start++;
        }
        else
        {
            cnt++;

            sum -= primes[start];
            start++;
        }
    }
    std::cout << cnt << '\n';
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