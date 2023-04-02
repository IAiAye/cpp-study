#include <iostream>
#include <vector>
using namespace std;

int arr[7] = {0};
int n, m;

void dfs(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return; // 개수를 다채우면 리턴
    }
    for (int j = num; j < n; j++)
    {
        arr[cnt] = j + 1;
        dfs(j, cnt + 1); // num을 넘겨서 시작하는 숫자 정해주기
    }
}
int main()
{
    cin >> n >> m;
    dfs(0, 0);
    return 0;
}