#include <iostream>
#include <string>
using namespace std;
int main()
{
    string A;
    string B;
    cin >> A >> B;
    
    if (A.length() < B.length())
    {
        string temp;
        temp = A;
        A = B;
        B = temp;
    }
    int length = A.length();

    int *arr = new int[length + 1];
    for (int i = 0; i < length; i++)
    {
        arr[i + 1] = A[i] - '0';
    }
    
    for (int i = 0; i < length; i++)
    {
        if (i < B.length())
        {
            arr[length - i] += B[B.length() - 1 - i] - '0';
        }
        if (arr[length - i] > 9) // 자릿수 계산은 계속되어야 한다.
        {
            arr[length - i] -= 10;
            arr[length - 1 - i] += 1;
        }
    }
    if (arr[0] == 1)
    {
        cout << arr[0];
    }
    
    for (int i = 1; i <= length; i++)
    {
        cout << arr[i];
    }
    cout << '\n';
    delete[] arr;
}