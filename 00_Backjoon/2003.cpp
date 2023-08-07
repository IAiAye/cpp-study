#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

// int n = 4;
// int m = 2;
// vector<int> v = {1, 1, 1, 1};

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}

void Solution()
{
    int cnt = 0;
    int sum = v[0];
    int left = 0;
    int right = 0;

    while (right < n)
    {
        if (sum == m)
        {
            cnt++;
            sum += v[++right];
            // sum -= v[left++];
        }
        else if (sum > m)
            sum -= v[left++];
        else
            sum += v[++right];
    }
    cout << cnt << '\n';
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