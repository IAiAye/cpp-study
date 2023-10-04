#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int n, m, k;
vector<int> graph[301];
vector<pair <int, int>> dragon[301];
bool visited[301];

void Input()
{

}

void Solution()
{
    while (true)
    {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0)
            break;
        
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 0; i < k; i++)
        {
            int  c, s, n;
            cin >> c >> s >> n;
            dragon[c].push_back({s, n});
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;
            
            queue<int> q;
            vector<int> pos;

            visited[i] = true;
            q.push(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                pos.push_back(cur);
                for (int next : graph[cur])
                {
                    if(!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            int left = -1;
            int right = 100001;
            while (left + 1 < right)
            {
                int mid = (left + right) / 2;
                int temp = 0;
                for (int j : pos)
                {
                    for (auto &p : dragon[j])
                    {
                        // 현재의 mid값으로는 클리어 하지 못하기 때문에, 처음에 죽여야 한다.
                        if (p.second >= mid)
                            temp += p.first;
                    }
                }
                // 처음에 죽이는 값들을 모았을 때 mid보다 작다면, 범위를 작게 줄인다.
                if (temp <= mid)
                    right = mid;
                else
                    left = mid;
            }
            res += right;
        }
        
        cout << res << '\n';

        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
            dragon[i].clear();
            visited[i] = false;
        }
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