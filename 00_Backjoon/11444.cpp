#include <iostream>
using namespace std;

long long ans[2][2] = {{1, 0}, {0, 1}}; // 단위 행렬
long long mat[2][2] = {{1, 1}, {1, 0}}; // F2 F1 , F1 F0
long long tmp[2][2];
long long m = 1000000007;

void matrix_multi(long long x[2][2], long long y[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int sum = 0;
            for (int q = 0; q < 2; q++)
            {
                sum += ( x[i][q] * y[q][j] ) % m;
            }
            tmp[i][j] = sum % m;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
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
    long long n;
    cin >> n;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            matrix_multi(ans, mat);
        }
        matrix_multi(mat, mat); // 밑항이 a^2 -> a^4...로 증가
        n /= 2;
    }
    
    cout << ans[0][1] << '\n';

    return 0;
}
