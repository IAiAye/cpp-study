#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int board[9][9];
int cnt;
bool isEnd;

vector<int> Find(int idx)
{
    int y = idx / 9;
    int x = idx % 9;

    bool isNum[10] = {0, };

    for (int i = 0; i < 9; i++)
    {
        int num = board[y][i];
        if (!isNum[num])
        {
            isNum[num] = true;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        int num = board[i][x];
        if (!isNum[num])
        {
            isNum[num] = true;
        }
    }
    for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++)
    {
        for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++)
        {
            int num = board[i][j];
            if (!isNum[num])
            {
                isNum[num] = true;
            }
        }
    }
    
    vector<int> tmp;
    for (int i = 1; i <= 9; i++)
    {
        if (!isNum[i])
        {
            tmp.push_back(i);
        }
    }
    return tmp;
}

void DFS(int idx, int c)
{
    if (isEnd)
        return;

    if (c == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j];
            }
            cout << '\n';
        }
        isEnd = true;
        return;
    }

    int y = idx / 9;
    int x = idx % 9;

    if (board[y][x] != 0)
    {
        DFS(idx + 1, c);
    }
    else
    {
        vector<int> nums = Find(idx);
        if (!nums.empty())
        {
            for (int i = 0; i < nums.size(); i++)
            {
                board[y][x] = nums[i];
                DFS(idx + 1, c - 1);
                board[y][x] = 0;
            }
        }
    }
}


void Input()
{
    for (int i = 0; i < 9; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = str[j] - '0';
            if (board[i][j] == 0)
                cnt++;
        }
    }
}

void Solution()
{
    DFS(0, cnt);
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}