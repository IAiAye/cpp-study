#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num;
    int tmp_x, tmp_y;
    cin >> num;
    vector <int> x;
    vector <int> y;
    vector <int> rank;

    for (int i = 0; i < num; i++)
    {
        cin >> tmp_x >> tmp_y;
        x.push_back(tmp_x);
        y.push_back(tmp_y);
    }
    for (int i = 0; i < num; i++)
    {
        int cnt = 1;
        for (int j = 0; j < num; j++)
        {
            if (x[i] < x[j] && y[i] < y[j])
            {
                cnt++;
            }
        }
        rank.push_back(cnt);
    }
    for (int i = 0; i < num; i++)
    {
        cout << rank[i] << ' ';
    }
}
