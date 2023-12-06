#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 32001

int n, m;
int cnt[MAX];
vector<int> graph[MAX];
// 오름차순 정렬
priority_queue<int, vector<int>, greater<int>> pq;

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        cnt[b]++;
    }
}

void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            cnt[next]--;
            if (cnt[next] == 0)
                pq.push(next);
        }
    }
    cout << '\n';
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