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
    int tmp;
    map <int, int> dup;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        dup.insert({tmp, 0});
    }
    for (int j = 0; j < m; j++)
    {
        cin >> tmp;
        if (dup.find(tmp) != dup.end())
        {
            cnt++;
        }
    }
    cout << n + m - cnt * 2 << '\n';
}