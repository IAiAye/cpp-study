#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;

int c;

void Input()
{
    cin >> c;
}

void Solution()
{
    while (c--)
    {
        int n;
        cin >> n;
        vector<int> numbers(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
            sum += numbers[i];
        }
        int avg = sum * 100 / n;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (numbers[i] * 100 > avg)
                cnt++;
        }
        cnt = cnt * 1000000 / n;
        if (cnt % 10 >= 5)
        {
            cnt -= cnt % 10;
            cnt += 10;
        }
        else
            cnt -= cnt % 10;

        cnt /= 10;
        cout << fixed << std::setprecision(3);
        cout << (double)cnt / 1000 << '%' << '\n';
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