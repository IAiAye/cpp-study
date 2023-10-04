#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

int n;
vector<int> hp(3);
bool visited[61][61][61];

int add[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9},
};

void bfs()
{
    queue<pair <vector<int>, int>> q;
    q.push({hp, 0});
    visited[hp[0]][hp[1]][hp[2]] = true;

    while (!q.empty())
    {
        vector<int> cur = q.front().first;
        int cnt = q.front().second;

        if (cur[0] == 0 && cur[1] == 0 && cur[2] == 0)
        {
            cout << cnt << '\n';
            return;
        }

        q.pop();
        for (int i = 0; i < 6; i++)
        {
            vector<int> next(3);
            next[0] = cur[0] - add[i][0];
            next[1] = cur[1] - add[i][1];
            next[2] = cur[2] - add[i][2];
            if (next[0] < 0)
                next[0] = 0;
            if (next[1] < 0)
                next[1] = 0;
            if (next[2] < 0)
                next[2] = 0;
            
            if (!visited[next[0]][next[1]][next[2]])
            {
                visited[next[0]][next[1]][next[2]] = true;
                q.push({next, cnt + 1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> hp[i];
    
    bfs();
    
    return 0;
}
