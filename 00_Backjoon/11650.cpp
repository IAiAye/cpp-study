#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num, temp;
    int num_x,num_y;
    vector<pair<int, int>> xy;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> num_x >> num_y;
        xy.push_back({num_x, num_y});
    }
    sort(xy.begin(),xy.end());
    for (int i = 0; i < num; i++)
    {
        cout << xy[i].first << ' ' << xy[i].second << '\n';
    }
}