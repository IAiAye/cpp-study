#include <iostream>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int x, y, w, h;
    int tmp_x, tmp_y;
    cin >> x >> y;
    cin >> w >> h;
    if (x <= w / 2) tmp_x = x;
    else tmp_x = w - x;
    if (y <= h / 2) tmp_y = y;
    else tmp_y = h - y;
    if (tmp_x < tmp_y) cout << tmp_x;
    else cout << tmp_y;
}