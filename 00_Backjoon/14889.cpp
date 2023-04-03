#include <iostream>
using namespace std;

int stat[20][20];
bool ones[20];
bool start[20] = {0};
bool link[20] = {0};
int n;
int num_min = 100000000;

void cal(bool start[], bool link[])
{
    int sum_start = 0;
    int sum_link = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (start[i] && start[j])
            {
                sum_start += stat[i][j] + stat[j][i];
            }
            if (link[i] && link[j])
            {
                sum_link += stat[i][j] + stat[j][i];
            }
        }
    }
    if (num_min > abs(sum_start - sum_link))
    {
        num_min = abs(sum_start - sum_link);
    }
}

void dfs(int num, int cnt)
{
    if (cnt == n / 2)
    {
        for (int j = 0; j < n; j++)
        {
            link[j] = ones[j] - start[j];
        }
        cal(start, link);
        return;
    }
    for (int i = num; i < n; i++)
    {
        if (!start[i])
        {
            start[i] = 1;
            dfs(i + 1, cnt + 1);
            start[i] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 20; i++)
    {
        ones[i] = true;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> stat[i][j];
        }
    }
    dfs(0, 0);
    cout << num_min;
}