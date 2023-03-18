#include <iostream>
using namespace std;

void star(int i, int j, int num) // 한단위에서 별을 출력할지, 공백을 출력할지 검사.
{
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) cout << ' ';
    else
    {
        if (num / 3 == 0) cout << '*';
        else star(i, j, num / 3);
    }
}

int main()
{
    int N; // N은 3^k 꼴이다.
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            star(i, j, N);
        }
        cout << '\n';
    }
}