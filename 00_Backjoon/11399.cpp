#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> times;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        times.push_back(tmp);
    }
    sort(times.begin(),times.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += times[i] * (n - i);
    }
    cout << sum << '\n';

    return 0;
}
