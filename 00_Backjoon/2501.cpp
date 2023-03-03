#include <iostream>
using namespace std;
int main()
{
    int n, k;
    int ans = 0;
    int count = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if (count == k)
            {
                ans = i;
                break;
            }
        }
    }
    cout << ans;
}