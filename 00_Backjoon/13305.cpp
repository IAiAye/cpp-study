#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector <int> distance;

    int n;
    long long tmp;
    long long tmp_old;
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        distance.push_back(tmp);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        if (tmp > tmp_old && i != 0) // 전 주유소보다 비싸다면 전 주유소에서 충전하는게 맞다.
        {
            tmp = tmp_old;
        }
        tmp_old = tmp;
        sum += tmp_old * distance[i];
    }
    cout << sum << '\n';

    return 0;
}
