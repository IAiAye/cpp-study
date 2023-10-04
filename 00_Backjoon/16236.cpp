#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n;
int sea[20][20];
pair <int, int> baby;
int babySize = 2;
int EXP = 0;

int add_y[4] = {-1, 0, 0, 1};
int add_x[4] = {0, -1, 1, 0};

struct cmp
{
    bool operator()(pair <pair <int, int>, int>& a, pair <pair <int, int>, int>& b)
    {
        if (a.second > b.second)
            return true;
        else if (a.second == b.second)
        {
            if (a.first.first > b.first.first)
                return true;
            else if (a.first.first == b.first.first)
            {
                if (a.first.second > b.first.second)
                    return true;
            }
            
        }
        return false;
    }
};



int BFS()
{
    priority_queue<pair <pair <int, int>, int>, vector<pair <pair <int, int>, int>>, cmp> q;
    // queue<pair <pair <int, int>, int>> q;
    
    q.push({{baby.first, baby.second}, 0});
    int visited[20][20] = {0, };
    visited[baby.first][baby.second] = 1;
    sea[baby.first][baby.second] = 0;

    while (!q.empty())
    {
        int y = q.top().first.first;
        int x = q.top().first.second;
        int time = q.top().second;
        q.pop();

        if (sea[y][x] != 0 && sea[y][x] < babySize)
        {
            sea[y][x] = 9;
            baby.first = y;
            baby.second = x;
            EXP++;
            if (EXP == babySize)
            {
                babySize++;
                EXP = 0;
            }
            return time;
        }

        for (int i = 0; i < 4; i++)
        {
            int nexty = y + add_y[i];
            int nextx = x + add_x[i];

            if (0 <= nexty && nexty < n && 0 <= nextx && nextx < n)
            {
                if (!visited[nexty][nextx] && sea[nexty][nextx] <= babySize)
                {
                    visited[nexty][nextx] = 1;
                    q.push({{nexty, nextx}, time + 1});
                }
            }
        }
    }
    return 0;
}

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sea[i][j];
            if (sea[i][j] == 9)
                baby = {i, j};
        }
    }
}

void Solution()
{
    int ans = 0;
    while (true)
    {
        int t = BFS();
        if (t)
            ans += t;
        else
            break;
    }
    cout << ans << '\n';
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