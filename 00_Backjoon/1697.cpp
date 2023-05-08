#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool visited[100001];
// 0 ~ 100,000
int n, k;

// 숫자와 카운트를 큐에 넣기
queue <pair <int, int>> q;

int isIn(int a, int i)
{
    if (i == 0)
    {
        if (a - 1 > 0) return a - 1;
        else return false;
    }
    if (i == 1)
    {
        if (a + 1 <= 100000) return a + 1;
        else return false;
    }
    if (i == 2)
    {
        if (a * 2 <= 100000) return a * 2;
        else return false;
    }
    return false;
}

void bfs(int n)
{
    visited[n] = true;
    q.push({n, 0});

    while(!q.empty())
    {
        int a = q.front().first;
        int cnt = q.front().second;

        if (a == k)
        {
            cout << cnt << '\n';
            break;
        }

        q.pop();

        for (int i = 0; i < 3; i++)
        {
            if(isIn(a, i) && !visited[isIn(a, i)])
            {
                visited[isIn(a, i)] = true;
                q.push({isIn(a,i), cnt + 1});
            }
            else if (a == 1 && i == 0 && !visited[0])
            {
                visited[0] = true;
                q.push({0, cnt + 1});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    bfs(n);

    return 0;
}