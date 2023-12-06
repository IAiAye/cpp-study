#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int n, k, p;
vector<pair <int, int>> gems;
vector<int> backpacks;
priority_queue<int, vector<int>, less<int>> pq;

ll FillBackpack(int idx)
{
    while (p < n && gems[p].first <= backpacks[idx])
    {
        pq.push(gems[p++].second);
    }
    
    if (pq.empty())
        return 0LL;
    else
    {
        int ret = pq.top();
        pq.pop();
        return 1LL * ret;
    }
}

void Input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        gems.push_back({m, v});
    }
    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;
        backpacks.push_back(c);
    }
}

void Solution()
{
    ll sum = 0;
    sort(gems.begin(), gems.end());
    sort(backpacks.begin(), backpacks.end());

    for (int i = 0; i < k; i++)
    {
        sum += FillBackpack(i);
    }

    cout << sum << '\n';
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