#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int cnt = 0;
    string tmp;
    cin >> n >> m;
    vector <string> str_list;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        str_list.push_back(tmp);
    }
    sort(str_list.begin(), str_list.end());

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        cnt += binary_search(str_list.begin(), str_list.end(), tmp);
    }
    cout << cnt;
}