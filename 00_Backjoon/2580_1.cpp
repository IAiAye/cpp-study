#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int board[9][9];
vector <pair <int,int>> points;
int cnt = 0;
bool found = false;

bool check(pair <int, int> p)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[p.first][i] == board[p.first][p.second] && i != p.second) return false;
        if (board[i][p.second] == board[p.first][p.second] && i != p.first) return false;
    }
    for (int i = p.first / 3 * 3; i < p.first / 3 * 3 + 3; i++)
    {
        for (int j = p.second / 3 * 3; j < p.second / 3 * 3 + 3; j++)
        {
            if (board[i][j] == board[p.first][p.second] && i != p.first && j != p.second) return false;
        }
    }
    return true;
}

void sudoku(int n)
{
    if (n == cnt)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true;
        return;
    }
    for (int k = 1; k <= 9; k++)
    {
        board[points[n].first][points[n].second] = k;
        if (check(points[n])) sudoku(n + 1);
        if (found) return;
    }
    board[points[n].first][points[n].second] = 0;
    return;
}

int main()
{
    pair <int, int> point;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                cnt++;
                point.first = i;
                point.second = j;
                points.push_back(point);
            }
        }
    }
    sudoku(0);
}