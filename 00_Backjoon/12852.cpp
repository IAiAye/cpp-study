#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1000010
int n;
bool visited[MAX];

// num, num까지의 경로
queue <pair <int, vector<int>>> q;

void bfs(int n)
{
    vector <int> v = {n};
    q.push({n, v});

    while (!q.empty())
    {
        int num = q.front().first;
        vector <int> pathToNum = q.front().second;
        //std::cout << num << ' ' << visited[num] << '\n';
        q.pop();

        if (num == 1)
        {
            std::cout << pathToNum.size() - 1 << '\n';
            for (int i = 0; i < pathToNum.size(); i++)
            {
                std::cout << pathToNum[i] << ' ';
            }
            std::cout << '\n';
            return;
        }

        if (visited[num]) continue;
        visited[num] = true;

        if (num % 3 == 0)
        {
            pathToNum.push_back(num / 3);
            q.push({num / 3, pathToNum});
            pathToNum.pop_back();
        }
        if (num % 2 == 0)
        {
            pathToNum.push_back(num / 2);
            q.push({num / 2, pathToNum});
            pathToNum.pop_back();
        }
           
        pathToNum.push_back(num - 1);
        q.push({num - 1, pathToNum});
        pathToNum.pop_back();
    }
}

void Input()
{
    std::cin >> n;
}

void Solution()
{
    bfs(n);
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