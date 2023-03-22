#include <iostream>
using namespace std;

int n, m;
int arr[8] = {0};
int visited[8] = {0};

void dfs(int num)
{
    if (num == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[num] = i + 1;
            dfs(num + 1);
            visited[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;
    dfs(0);
}