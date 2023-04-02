#include <iostream>
#include <queue>
#include <set>
#include <utility>
using namespace std;
int sdoku[9][9];

// 명확한 해가 있을 때는 제대로 작동하지만, 임의로 입력해야하는 경우에는 뻗어버린다.

void sd(queue <pair <int,int>> &q)
{
    set <int> s;
    int row = q.front().first;
    int col = q.front().second;

    // 가로 확인
    for (int j = 0; j < 9; j++)
    {
        if (sdoku[row][j])
        {
            s.insert(sdoku[row][j]);
        }
    }
    // 세로 확인
    for (int i = 0; i < 9; i++)
    {
        if (sdoku[i][col])
        {
            s.insert(sdoku[i][col]);
        }
    }
    // 박스 확인
    for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
    {
        for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
        {
            if (sdoku[i][j])
            {
                s.insert(sdoku[i][j]);
            }   
        }
    }
    if (s.size() == 8)
    {
        int sum = 0;
        for (auto iter = s.begin(); iter != s.end(); iter++)
        {
            sum += *iter;
        }
        sdoku[row][col] = 45 - sum;
        q.pop();
    }
    else
    {
        q.push(q.front());
        q.pop();
    }
    if (q.empty())
    {
        return;
    }
    sd(q);
}

int main()
{
    int tmp;
    queue <pair <int,int>> q;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> tmp;
            sdoku[i][j] = tmp;
            if (tmp == 0) q.push({i,j});
        }
    }
    sd(q);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sdoku[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}