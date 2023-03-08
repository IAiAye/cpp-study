#include <iostream>
using namespace std;
int main()
{
    int num, cut, temp;
    cin >> num >> cut;
    int *arr = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    for (int i = 1; i < num; i++)
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
    cout << arr[num - cut] << '\n';

    delete[] arr;
}