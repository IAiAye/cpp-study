#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 1000000001

int a, b;
// bool visited[MAX];

void bfs()
{
    queue<pair <ll, int>> q;
    q.push({a, 1});
    // visited[a] = true;

    while (!q.empty())
    {
        ll cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == b)
        {
            cout << cnt << '\n';
            return;
        }

        ll next = cur * 2;
        if (next < MAX && next <= b)
        {
            q.push({next, cnt + 1});
            // visited[next] = true;
        }

        next = cur * 10 + 1;
        if (next < MAX && next <= b)
        {
            q.push({next, cnt + 1});
            // visited[next] = true;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> a >> b;
    bfs();
    
    return 0;
}