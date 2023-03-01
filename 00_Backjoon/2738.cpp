#include <iostream>
using namespace std;
int main()
{
    int row, column;
    cin >> row >> column;
    int **arrA = new int*[row]; // 2중 포인터
    int **arrB = new int*[row]; // arr의 인덱스가 일차원 배열을 가르키는 형태.

    for (int i = 0; i < row; i++)
    {
        arrA[i] = new int[column]; // arr의 인덱스에 1차원 배열포인터 할당.
        for (int j = 0; j < column; j++)
        {
            cin >> arrA[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        arrB[i] = new int[column];
        for (int j = 0; j < column; j++)
        {
            cin >> arrB[i][j];
        }
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << arrA[i][j] + arrB[i][j] << " ";
        }
        cout << "\n";
    }
    

    for (int i = 0; i < row; i++)
    {
        delete[] arrA[i];
    }
    for (int i = 0; i < row; i++)
    {
        delete[] arrB[i];
    }
    delete[] arrA;
    delete[] arrB;
}