#include <iostream>
using namespace std;

bool isPrime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if(num % i == 0) return false; // 루트 n까지 나눠지는 약수가 있다.
    }
    return true;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0) break;
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (i == 2)
            {
                cnt++;
                continue;
            }
            else
            {
                if (i % 2 == 0) i++;
                while (!isPrime(i)) i += 2;
                if (i <= 2 * n)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}