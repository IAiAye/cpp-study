#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c, ans;
vector <int> items;
// 합해서 나올 수 있는 모든 수가 포함되어있다.
vector <long long> firstHalf;
vector <long long> SecondHalf;

void dfs (int start, int end, vector <long long>& v, long long sum)
{
    if (start > end)
    {
        v.push_back(sum);
        return;
    }
    
    // start 번째 숫자를 포함 안하거나
    dfs(start + 1, end, v, sum);
    // start 번째 숫자를 포함하거나
    dfs(start + 1, end, v, sum + items[start]);
}

void Input()
{
    std::cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int item;
        std::cin >> item;
        items.push_back(item);
    }
}

void Solution()
{
    dfs(0, n / 2 - 1, firstHalf, 0);
    dfs(n / 2, n - 1, SecondHalf, 0);

    sort(SecondHalf.begin(), SecondHalf.end());

    for (int i = 0; i < firstHalf.size(); i++)
    {
        // c에서 firstHalf[i] 만큼 뺐을 때, 그만큼보다 작은 secondHalf의 개수를 다 더해준다.
        ans += upper_bound(SecondHalf.begin(), SecondHalf.end(), c - firstHalf[i]) - SecondHalf.begin();
    }
    std::cout << ans << '\n';
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