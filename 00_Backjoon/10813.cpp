#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int N, M;
    int i_, j_;
    int temp;

    cin >> N >> M;
    int *arr_ = new int[N];

    for (int i = 0; i < N; i++)
    {
        arr_[i] = i + 1;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> i_ >> j_;
        temp = arr_[i_ - 1];
        arr_[i_ - 1] = arr_[j_ - 1];
        arr_[j_ - 1] = temp;
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr_[i] << " ";
    }

    delete[] arr_;
    return 0;
}