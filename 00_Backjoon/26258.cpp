#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ull = unsigned long long;

int n, q;
vector<pair <int, int>> graph;

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        graph.push_back(make_pair(x, y));
    }
    cin >> q;
}

void Solution()
{
    while (q--)
    {
        double k;
        cin >> k;

        int left = 0;
        int right = n - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (graph[mid].first < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (graph[right].second == graph[left].second)
            cout << 0 << '\n';
        else if (graph[right].second < graph[left].second)
            cout << 1 << '\n';
        else
            cout << -1 << '\n';   
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