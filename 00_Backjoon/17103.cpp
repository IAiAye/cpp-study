#include <iostream>
using namespace std;
#define MAX 1000000
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int prime[MAX + 1] = {0};
    for (int i = 2; i < MAX + 1; i++) prime[i] = i;
    for (int i = 2; i < MAX + 1; i++)
    {
        if (prime[i])
        {
            for (int j = i * 2; j < MAX + 1; j += i) prime[j] = 0;
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int even;
        cin >> even;
        int cnt = 0;
        if (even == 4)
        {
            cout << 1 << '\n';
            continue;
        }
        
        for (int i = 3; i <= even / 2; i += 2)
        {
            if (prime[i] + prime[even - i] == even)
            {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }   
}