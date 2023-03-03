#include <iostream>
using namespace std;
int main()
{
    int test_case;
    int n;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        cin >> n;
        for (int j = n / 2; j > 1; j--) // 소수는 2 이상으로는 홀수만 있으므로 2씩 빼면서 확인하면 더 빠르다.
        {
            bool isPrime = true;
            for (int k = 2; k < j; k++)
            {
                if (j % k == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                for (int k = 2; k < n - j; k++)
                {
                    if ((n - j) % k == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }
            }
            if (isPrime)
            {
                cout << j << ' ' << n - j << '\n';
                break;
            }
        }
    }
}