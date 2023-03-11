#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int sum = i;
        for (int j = 1000000; j != 1; j /= 10)
        {
            sum += (i % j) / (j / 10);
        }
        if (sum == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << '0';
    return 0;
}