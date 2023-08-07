#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
using ull = unsigned long long;

int n;
bool visited[11];
vector<int> cost;
vector<pair <int, int>> discount[11];

int MIN = 200000;

void dfs(int cnt, int sum, vector<int> cost)
{
    if (cnt == n)
    {
        MIN = min(MIN, sum);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            int s = sum + cost[i];

            vector<int> tmp = cost;
            int size = discount[i].size();

            for (int j = 0; j < size; j++)
            {
                int a = discount[i][j].first;
                int d = discount[i][j].second;
                tmp[a] -= d;
                if (tmp[a] <= 0)
                    tmp[a] = 1;    
            }
            dfs(cnt + 1, s, tmp);

            visited[i] = false;
        }
    }
}

void Input()
{
    cin >> n;
    cost.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            int a, d;
            cin >> a >> d;
            discount[i].push_back(make_pair(a, d));
        }
    }
}

void Solution()
{
    dfs(0, 0, cost);
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