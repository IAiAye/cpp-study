#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

int n, m;
char Map[600][600];
bool visited[600][600];
int meY, meX;
int cnt;

struct Pos
{
    int y;
    int x;
    Pos(int y, int x) : y(y), x(x) {}
    Pos operator+(const Pos& a)
    {
        return Pos(y + a.y, x + a.x);
    }
};

Pos dir[4] = {Pos(-1, 0), Pos(1, 0), Pos(0, -1), Pos(0, 1)};

void bfs()
{
    queue<Pos> q;
    q.push(Pos(meY, meX));
    visited[meY][meX] = true;

    while (!q.empty())
    {
        Pos pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            Pos nextPos = pos + dir[i];
            if (nextPos.y >= 0 && nextPos.y < n && nextPos.x >= 0 && nextPos.x < m && !visited[nextPos.y][nextPos.x])
            {
                visited[nextPos.y][nextPos.x] = true;
                if (Map[nextPos.y][nextPos.x] == 'X')
                    continue;
                else if (Map[nextPos.y][nextPos.x] == 'P')
                    cnt++;
                q.push(nextPos);
            }
        }
    }
}

void Input()
{
    cin >> n >> m;
    // n = 3;
    // m = 5;

    // string strs[3] = {"OOOPO", "OIOOX", "OOOXP"};
    for (int y = 0; y < n; y++)
    {
        string str;
        cin >> str;
        for (int x = 0; x < m; x++)
        {
            Map[y][x] = str[x];
            if (str[x] == 'I')
            {
                meY = y;
                meX = x;
            }
        }
    }
}

void Solution()
{
    bfs();
    if (cnt == 0)
        cout << "TT" << '\n';
    else
        cout << cnt << '\n';
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