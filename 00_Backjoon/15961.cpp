#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int n, d, k, c;
vector<int> dish;
int sushi[3001];

void Input()
{
    cin >> n >> d >> k >> c;
    dish.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> dish[i];
}

void Solution()
{
    int numSushi = 0;
    for (int i = 1; i <= k; i++)
    {
        if (dish[i] != c && sushi[dish[i]]++ == 0)
            numSushi++;
    }
    int ans = numSushi;

    for (int i = 2; i <= n; i++)
    {
        int left = i - 1;
        int right = (i + k - 1) % n;
        if (right == 0)
            right = n;
        
        if (dish[left] != c && --sushi[dish[left]] == 0)
            numSushi--;
        if (dish[right] != c && sushi[dish[right]]++ == 0)
            numSushi++;
        
        ans = max(ans, numSushi);
    }
    cout << ans + 1 << '\n';
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