#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <pair <int, int>> v;

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back({tmp, i});
    }
}

void Solution()
{
    stable_sort(v.begin(), v.end());

    int maxValue = 0;
    for (int i = 0; i < N; i++)
    {
        // 왼쪽으로 이동한 만큼 실행 된다.
        maxValue = max(v[i].second - i, maxValue);
        //cout << v[i].second - i << '\n';
    }
    cout << maxValue + 1 << '\n';
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