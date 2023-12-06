#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int n, MAX;
vector<vector<int>> board(20, vector<int>(20, 0));

void Up(int col, vector<vector<int>>& b)
{
    vector<int> tmp;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int num = b[i][col];
        if (num == 0)
            continue;
        
        q.push(num);
    }
    while (!q.empty())
    {
        int first = q.front();
        q.pop();

        if (!q.empty() && first == q.front())
        {
            tmp.push_back(first * 2);
            q.pop();
        }
        else
            tmp.push_back(first);
    }
    while (tmp.size() < n)
        tmp.push_back(0);

    for (int i = 0; i < n; i++)
        b[i][col] = tmp[i];
}

void Down(int col, vector<vector<int>>& b)
{
    vector<int> tmp;
    queue<int> q;
    for (int i = n - 1; i >= 0; i--)
    {
        int num = b[i][col];
        if (num == 0)
            continue;
        
        q.push(num);
    }
    while (!q.empty())
    {
        int first = q.front();
        q.pop();

        if (!q.empty() && first == q.front())
        {
            tmp.push_back(first * 2);
            q.pop();
        }
        else
            tmp.push_back(first);
    }
    while (tmp.size() < n)
        tmp.push_back(0);

    for (int i = n - 1; i >= 0; i--)
        b[i][col] = tmp[(n - 1) - i];
}

void Left(int row, vector<vector<int>>& b)
{
    vector<int> tmp;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int num = b[row][i];
        if (num == 0)
            continue;
        q.push(num);
    }
    while (!q.empty())
    {
        int first = q.front();
        q.pop();

        if (!q.empty() && first == q.front())
        {
            tmp.push_back(first * 2);
            q.pop();
        }
        else
            tmp.push_back(first);
    }
    while (tmp.size() < n)
        tmp.push_back(0);

    for (int i = 0; i < n; i++)
        b[row][i] = tmp[i];
}

void Right(int row, vector<vector<int>>& b)
{
    vector<int> tmp;
    queue<int> q;
    for (int i = n - 1; i >= 0; i--)
    {
        int num = b[row][i];
        if (num == 0)
            continue;
        q.push(num);
    }
    while (!q.empty())
    {
        int first = q.front();
        q.pop();

        if (!q.empty() && first == q.front())
        {
            tmp.push_back(first * 2);
            q.pop();
        }
        else
            tmp.push_back(first);
    }
    while (tmp.size() < n)
        tmp.push_back(0);

    for (int i = n - 1; i >= 0; i--)
        b[row][i] = tmp[(n - 1) - i];
}

void DFS(int cnt, vector<vector<int>> b)
{
    if (cnt == 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                MAX = max(MAX, b[i][j]);
            }
        }
        return;
    }

    vector<vector<int>> up = b;
    for (int i = 0; i < n; i++)
    {
        Up(i, up);
    }
    DFS(cnt + 1, up);

    vector<vector<int>> down = b;
    for (int i = 0; i < n; i++)
    {
        Down(i, down);
    }
    DFS(cnt + 1, down);

    vector<vector<int>> left = b;
    for (int i = 0; i < n; i++)
    {
        Left(i, left);
    }
    DFS(cnt + 1, left);

    vector<vector<int>> right = b;
    for (int i = 0; i < n; i++)
    {
        Right(i, right);
    }
    DFS(cnt + 1, right);
}

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
}

void Solution()
{
    DFS(0, board);
    cout << MAX << '\n';
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