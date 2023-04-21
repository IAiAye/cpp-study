#include <iostream>
using namespace std;

int ans[5][5];
int mat[5][5];
int tmp[5][5];
long long n, b;

void matrix_multi(int x[5][5], int y[5][5])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int q = 0; q < n; q++)
            {
                sum += ( x[i][q] * y[q][j] ) % 1000;
            }
            tmp[i][j] = sum % 1000;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j]; // 거듭제곱의 a, 즉 밑항이 되는 행렬
        }
        ans[i][i] = 1; // 단위행렬로 만들기. (1)
    }
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            matrix_multi(ans, mat);
        }
        matrix_multi(mat, mat); // 밑항이 a^2 -> a^4...로 증가
        b /= 2;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
