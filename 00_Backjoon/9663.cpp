#include <iostream>
using namespace std;

int cnt = 0;

bool check(int **board, int n, int row, int col)
{
    for (int i = 0; i < row; i++) // 위 검사
    {
        if (board[i][col] == 1) return false;
    }
    // 왼쪽 위 대각선 검사
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j] == 1) return false;
    }
    // 오른쪽 위 대각선 검사
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 
    {
        if (board[i][j] == 1) return false;
    }
    return true;
}

void n_queen(int** board, int n, int row)
{
    if (n == row)
    {
        cnt++;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (check(board, n, row, i))
        {
            board[row][i] = 1;
            n_queen(board, n, row + 1);
            board[row][i] = 0;
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int** board;
    board = new int*[N];
    for (int i = 0; i < N; i++)
    {
        board[i] = new int[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    n_queen(board, N, 0);
    cout << cnt;

    for (int i = 0; i < N; i++)
    {
        delete[] board[i];
    }
    delete[] board;
    return 0;
}