#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    double num, temp;
    double sum = 0;
    cin >> num;
    vector <int> v;

    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        sum += temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout << round(sum / num) << '\n' << v[(num - 1) / 2] << '\n' << "최빈값" << '\n' << v.back() - v.front() << '\n';

}