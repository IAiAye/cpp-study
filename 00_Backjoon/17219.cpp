#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map <string, string> site;

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        site[a] = b;
    }
}

void Solution()
{
    for (int i = 0; i < m; i++)
    {
        string key;
        cin >> key;
        cout << site[key] << '\n';
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