#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
ll a, b;
#define MAX 10000001
bool isPrime[MAX];
vector<int> prime;

void Input()
{
    cin >> a >> b;
}

void Solution()
{
    int cnt = 0;

    for (int i = 2; i < MAX; i++)
    {
        if (!isPrime[i])
        {
            prime.push_back(i);
            for (int j = 2 * i; j < MAX; j += i) 
                isPrime[j] = true;
        }
    }

    for (auto it : prime)
    {
        ll curr = 1LL * it;
        ll temp = curr;
        while (temp <= b / curr)
        {
            temp *= curr;
            if (temp >= a)
                cnt++;
        }
    }

    cout << cnt << '\n';
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