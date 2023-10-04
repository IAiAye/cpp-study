#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n, m;
short board[51][51];
vector<pair <int, int>> house;
vector<pair <int, int>> chicken;
vector<pair <int, int>> chosen;
int MIN = 10000;

int absMinus(pair<int, int>& a, pair<int, int>& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int idx, int cnt)
{
    if (cnt == m)
    {
        int chosenMIN = 0;
        for (auto h : house)
        {
            int hMIN = 200;
            for (auto c : chosen)
            {
                hMIN = min(hMIN, absMinus(h, c));
            }
            chosenMIN += hMIN;
        }
        MIN = min(chosenMIN, MIN);
        return;
    }

    int cNum = chicken.size();
    for (int i = idx; i < cNum; i++)
    {
        // 뽑을 수 있는게 뽑아야 하는 것보다 작으면 return
        if (cNum - i < m - cnt)
            return;

        chosen.push_back(chicken[i]);
        dfs(i + 1, cnt + 1);
        chosen.pop_back();
    }
    
}

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                house.push_back({i, j});
            else if (board[i][j] == 2)
                chicken.push_back({i, j});
        }   
    }
}

void Solution()
{
    dfs(0, 0);
    cout << MIN << '\n';
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