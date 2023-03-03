#include <iostream>
using namespace std;
int main()
{
    int n;
    while (1)
    {
        int sum = 0;
        int count = 0;
        int arr[10000] = {0};
        
        cin >> n;
        if (n == -1)
        {
            break;
        }
        
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                sum += i;
                arr[count] = i;
                count += 1;
            }
        }
        if (sum == n)
        {
            cout << n;
            for (int i = 0; i < count; i++)
            {
                if (i == 0)
                {
                    cout << " = ";
                } else cout << " + ";
                cout << arr[i];
            }
        } else cout << n << " is NOT perfect.";
        cout << '\n';
    }
}