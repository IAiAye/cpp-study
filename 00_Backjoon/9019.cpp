#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int t;
bool visited[10000];
queue <pair <pair <int, int>, string>> q;
string ans;

int fD(int num)
{
    return (num * 2) % 10000;
}
int fS(int num)
{
    if (num == 0) return 9999;
    else return num - 1;
}
int fL(int num)
{
    int d1 = num / 1000;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    return (((d2 * 10 + d3) * 10 + d4) * 10 + d1);
}
int fR(int num)
{
    int d1 = num / 1000;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    return (((d4 * 10 + d1) * 10 + d2) * 10 + d3);
}

void bfs(int a, int b)
{
    for (int i = 0; i < 10000; i++)
    {
        visited[i] = false;
    }
    ans = "";

    q.push({{a, 0}, ans});
    visited[a] = true;

    while (!q.empty())
    {
        int num = q.front().first.first;
        int cnt = q.front().first.second;
        string ans = q.front().second;

        q.pop();

        if (num == b)
        {
            cout << ans << '\n';
            while (!q.empty())
            {
                q.pop();
            }
            
            return;
        }
        
        int D = fD(num);
        int S = fS(num);
        int L = fL(num);
        int R = fR(num);

        if (!visited[D])
        {
            q.push({{D, cnt + 1}, ans + 'D'});
            visited[D] = true;
        }
        if (!visited[S])
        {
            q.push({{S, cnt + 1}, ans + 'S'});
            visited[S] = true;
        }
        if (!visited[L])
        {
            q.push({{L, cnt + 1}, ans + 'L'});
            visited[L] = true;
        }
        if (!visited[R])
        {
            q.push({{R, cnt + 1}, ans + 'R'});
            visited[R] = true;
        }
        

    }
    
}

void Input()
{
    cin >> t;
}

void Solution()
{
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
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