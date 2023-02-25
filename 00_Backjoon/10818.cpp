#include <iostream>

using namespace std;

int main()
{
    int N;
    int MAX_, MIN_;
    cin >> N;
    int *A = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    MAX_ = A[0];
    MIN_ = A[0];
    for (int i = 1; i < N; i++)
    {
        if (A[i] < MIN_)
        {
            MIN_ = A[i];
        }
        if (A[i] > MAX_)
        {
            MAX_ = A[i];
        }
    }
    cout << MIN_ << " " << MAX_;
    delete[] A;
    return 0;
}