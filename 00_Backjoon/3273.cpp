#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x;
vector <int> arr;

void Input()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        arr.push_back(temp);
    }
    std::cin >> x;
}

void Solution()
{
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = n - 1;

    int ans = 0;

    while (start != end)
    {
        int sum = arr[start] + arr[end];

        if (sum == x)
        {
            ans++;
            start++;
        }
        else if (sum < x) start++;
        else end--;
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