#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

// 기울기는 최소 1/9999 에서 최대 9999999까지.
int n, width, reflexMax;
vector<pair <int, int>> v;
map<pair <int, int>, int> m;

int gcd(int a, int b)
{
    int temp;
    while (b > 0)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}

void Input()
{
    cin >> n >> width >> reflexMax;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
}

void Solution()
{
    int MAX = 1;
    for (int k = 0; k < reflexMax; k++)
    {
        for (int i = 0; i < n; i++)
        {
            int x = v[i].first;
            int y = v[i].second;

            if (k % 2 == 0)
                x = k * width + x;
            else
                x = k * width + (width - x);
            
            int GCD = gcd(x, y);
            x /= GCD;
            y /= GCD;
            pair <int, int> p = make_pair(x, y);
            if (m.find(p) != m.end())
            {
                m[p] += 1;
                MAX = max(m[p], MAX);
            }
            else
                m[p] = 1;
        }
    }

    cout << MAX << '\n';
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