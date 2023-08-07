#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

int t, n;
unordered_map<string, int> m;

void Input()
{
    cin >> t;
}

void Solution()
{
    while(t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string a, b;
            
            cin >> a >> b;
            if (m.find(b) != m.end())
                m[b]++;
            else
                m[b] = 1;
        }
        int sum = 1;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            sum *= (it->second + 1);
        }
        cout << sum - 1 << '\n';
        m.clear();
    }
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
    
    return 0;
}