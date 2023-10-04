#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int tc;
int n;

int compare(string& a, string& b)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] != b[i])
            cnt++;
    }
    return cnt;
}

void Input()
{
    cin >> tc;
}

void Solution()
{
    while (tc--)
    {
        int sum = 100;
        cin >> n;
        
        vector<string> s;

        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            s.push_back(tmp);
        }

        if (n > 32)
        {
            cout << 0 << '\n';
            continue;
        }
        
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    sum = min(sum, compare(s[i], s[j]) + compare(s[j], s[k]) + compare(s[i], s[k]));
                    if (sum == 0)
                        break;
                }
                if (sum == 0)
                    break;
            }
            if (sum == 0)
                break;
        }
        cout << sum << '\n';
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