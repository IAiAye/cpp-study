#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int cnt = 0;
    cin >> n >> m;
    string tmp;
    map <string, int> dbj;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        dbj.insert({tmp, 0});
    }
    for (int j = 0; j < m; j++)
    {
        cin >> tmp;
        if (dbj.find(tmp) != dbj.end())
        {
            dbj[tmp]++;
            cnt++;
        }
    }
    cout << cnt << '\n';
    for (auto iter = dbj.begin(); iter != dbj.end(); iter++)
    {
        if (iter->second == 1)
        {
            cout << iter->first << '\n';
        }
    }
}