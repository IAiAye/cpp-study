#include <iostream>
using namespace std;
int main()
{
    int arr[9][9];
    int val_max = -1;
    int pos_i, pos_j;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] > val_max)
            {
                val_max = arr[i][j];
                pos_i = i;
                pos_j = j;
            }
        }
    }
    cout << val_max << "\n" << pos_i + 1 << " " << pos_j + 1;
}