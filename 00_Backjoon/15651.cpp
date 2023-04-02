#include <iostream>
#include <vector>
using namespace std;

int arr[7] = {0};
int n, m;

void dfs(int cnt)
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
    for (int j = 0; j < n; j++)
    {
        arr[cnt] = j + 1;
        dfs(cnt + 1);
    }
}
int main()
{
    cin >> n >> m;
    dfs(0);
    return 0;
}