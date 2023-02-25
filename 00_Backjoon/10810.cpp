#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int N, M;
    int i, j, k;

    cin >> N >> M;
    int *arr_ = new int[N];

    for (int q = 0; q < M; q++)
    {
        cin >> i >> j >> k;
        for (int p = i; p <= j; p++)
        {
            arr_[p - 1] = k;
        }
    }
    for (int r = 0; r < N; r++)
    {
        cout << arr_[r] << " ";
    }
    
    delete[] arr_;
    return 0;
}