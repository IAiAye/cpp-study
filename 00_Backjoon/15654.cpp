#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int visited[8];
vector <int> numbers;
vector <int> results;

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << results[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;

        // 방문 체크해주고
        visited[i] = true;
        results.push_back(numbers[i]);
        dfs(cnt + 1);
        // 탐색하고 나오면 다시 꺼주기.
        visited[i] = false;
        results.pop_back();
    }
    
}

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
}

void Solution()
{
    sort(numbers.begin(), numbers.end());
    dfs(0);
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