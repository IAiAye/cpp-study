#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int N, M;
    int num_i, num_j; // i<j

    cin >> N >> M;

    int *arr1 = new int[N];
    int *arr2 = new int[N];
    for (int i = 0; i < N; i++)
    {
        arr1[i] = i + 1;
    }  
    for (int i = 0; i < M; i++)
    {
        cin >> num_i >> num_j; // 1 5
        num_i--; // 0
        num_j--; // 4
        copy(arr1 + num_i, arr1 + num_j + 1, arr2); // 마지막에서 주소 하나 더 추가.

        for (int i = 0; i <= num_j - num_i; i++) // 4
        {
            arr1[num_i + i] = arr2[num_j - num_i - i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr1[i] << " ";
    }

    delete[] arr1;
    delete[] arr2;
    return 0;
}