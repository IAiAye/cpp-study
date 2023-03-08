#include <iostream>
using namespace std;
int main()
{
    int temp;
    int sum = 0;
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> temp;
        sum += temp;
        arr[i] = temp;
    }
    for (int i = 1; i < 5; i++)
    {
        for (int j = i; j != 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << sum / 5 << '\n' << arr[2] << '\n';
}