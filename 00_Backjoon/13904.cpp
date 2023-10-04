#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;

int n;
// 점수, 일수
vector<pair <int, int>> greedy;
int arr[1001];

bool cmp(pair <int, int> a, pair <int, int> b)
{
    return a.second > b.second;
}

void Input()
{
    cin >> n;
    greedy.resize(n);

    for (int i = 0; i < n; i++)
        cin >> greedy[i].first >> greedy[i].second;
}

void Solution()
{
    sort(greedy.begin(), greedy.end(), cmp);

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int day = greedy[i].first;
        int score = greedy[i].second;
        for (int j = day; j > 0; j--)
        {
            if (arr[j] == 0)
            {
                arr[j] = score;
                sum += score;
                break;
            }
        }
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