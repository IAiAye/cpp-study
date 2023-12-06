#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
using ll = long long;

int n, m;
int board[1001][1001];
int visited[1001][1001];

int chunk_id = 0;
int chunk[1001][1001];
vector<int> chunk_size;

int add_y[4] = {-1, 0, 1, 0};
int add_x[4] = {0, 1, 0, -1};

void BFS(int y, int x)
{
    queue<pair<int, int>> q;

    visited[y][x] = true;
    chunk[y][x] = chunk_id;
    q.push({y, x});
    int cnt = 1;

    while (!q.empty())
    {
        int curr_y = q.front().first;
        int curr_x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_y = curr_y + add_y[i];
            int next_x = curr_x + add_x[i];

            if (1 <= next_y && next_y <= n && 1 <= next_x && next_x <= m)
            {
                if (!visited[next_y][next_x] && board[next_y][next_x] == 0)
                {
                    visited[next_y][next_x] = true;
                    chunk[next_y][next_x] = chunk_id;
                    q.push({next_y, next_x});
                    cnt++;
                }
            }
        }
    }
    chunk_size.push_back(cnt);
    chunk_id++;
}

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
            board[i][j] = str[j - 1] - '0';
    }
}

void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == 0 && !visited[i][j])
                BFS(i, j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == 1)
            {
                int cnt = 1;
                set<int> check_id;
                
                for (int k = 0; k < 4; k++)
                {
                    int next_y = i + add_y[k];
                    int next_x = j + add_x[k];

                    if (1 <= next_y && next_y <= n && 1 <= next_x && next_x <= m && board[next_y][next_x] == 0)
                    {
                        int curr_id = chunk[next_y][next_x];
                        if (check_id.find(curr_id) == check_id.end())
                        {
                            cnt += chunk_size[curr_id];
                            check_id.insert(curr_id);
                        }
                    }
                }
                cout << cnt % 10;
            }
            else
                cout << 0;
        }
        cout << '\n';
    }
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