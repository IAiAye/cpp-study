#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    vector <int> tri(3);
    cin >> tri[0] >> tri[1] >> tri[2];
    sort(tri.begin(), tri.end());
    if (tri[0] + tri[1] <= tri[2])
    {
        cout << (tri[0] + tri[1]) * 2 - 1;
    } else cout << tri[0] + tri[1] + tri[2];
}