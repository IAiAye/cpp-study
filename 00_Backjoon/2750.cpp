#include <iostream>
using namespace std;
int main()
{
    int num, temp;
    cin >> num;
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
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << endl;
    }
    
    delete[] arr;
}