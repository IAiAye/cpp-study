#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num, temp;
    int num_x,num_y;
    vector<pair<int, int>> yx;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> num_x >> num_y;
        yx.push_back({num_y, num_x});
    }
    sort(yx.begin(),yx.end());
    for (int i = 0; i < num; i++)
    {
        cout << yx[i].second << ' ' << yx[i].first << '\n';
    }
}