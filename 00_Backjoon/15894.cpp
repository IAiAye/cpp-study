#include <iostream>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int min_x = 10001, min_y = 10001;
    int max_x = -10001, max_y = -10001;
    for (int i = 0; i < n; i++)
    {
        int x, y = 0;
        cin >> x >> y;
        if (x <= min_x) min_x = x;
        if (y <= min_y) min_y = y;
        if (x >= max_x) max_x = x;
        if (y >= max_y) max_y = y;
    }
    cout << (max_x - min_x) * (max_y - min_y);
}