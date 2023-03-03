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
        for (int j = n / 2; j > 1; j--)
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