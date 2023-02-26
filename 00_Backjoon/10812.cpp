#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    int begin, end, mid;

    cin >> n >> m;

    int *arr = new int[n];
    int *arr_temp = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> begin >> end  >> mid;
        copy(arr + begin - 1, arr + end, arr_temp); // 설정한 구간을 임시 저장.

        for (int j = 0; j <= end  - mid; j++) // mid ~ end 까지 앞으로 당기기.
        {
            arr[begin - 1 + j] = arr_temp[j + mid - begin];
        }
        for (int k = 0; k < mid - begin; k++)
        {
            arr[begin + end - mid + k] = arr_temp[k];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    delete[] arr;
    delete[] arr_temp;
    return 0;
}