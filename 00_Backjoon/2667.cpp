#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int map[25][25];
vector <int> house_nums;

int n;
// 기존의 숫자 1과 구별하기 위해 2단지부터 시작
int danji = 2;
int house_num;

void dfs(int i, int j)
{
    // visited를 대신한다. 1이 아니라면 방문한 것
    map[i][j] = danji;
    house_num++;
    if (i > 0 && map[i - 1][j] == 1) dfs(i - 1, j);
    if (j > 0 && map[i][j - 1] == 1) dfs(i, j - 1);
    if (i < n - 1 && map[i + 1][j] == 1) dfs(i + 1, j);
    if (j < n - 1 && map[i][j + 1] == 1) dfs(i, j + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1) 
            {
                dfs(i, j);
                house_nums.push_back(house_num);
                house_num = 0;
                danji++;
            }
        }
    }
    sort(house_nums.begin(), house_nums.end());

    cout << danji - 2 << '\n';
    for (int i = 0; i < danji - 2; i++)
    {
        cout << house_nums[i] << '\n';
    }

    return 0;
}