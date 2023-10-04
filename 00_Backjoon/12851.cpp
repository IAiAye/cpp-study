#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n, k;
bool visited[100001];
bool firstFind;
int firstTime;
int cnt;

void BFS()
{
    priority_queue<pair <int, int>> pq;
    pq.push({0, n});
    
    while (!pq.empty())
    {
        int time = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        visited[pos] = true;

        if (firstFind && time > firstTime)
            return;

        if (pos == k)
        {
            if (!firstFind)
            {
                cout << time << '\n';
                firstFind = true;
                firstTime = time;
            }
            cnt++;
        }

        if (pos - 1 >= 0 && !visited[pos - 1])
        {
            pq.push({-(time + 1), pos - 1});
        }
        if (pos + 1 <= 100000 && pos < k && !visited[pos + 1])
        {
            pq.push({-(time + 1), pos + 1});
        }
        if (pos * 2 <= 100000 && pos < k && !visited[pos * 2])
        {
            pq.push({-(time + 1), pos * 2});
        }
    }
    
}

void Input()
{
    cin >> n >> k;
}

void Solution()
{
    BFS();
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