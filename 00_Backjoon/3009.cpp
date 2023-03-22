#include <iostream>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int pos_x[1001] = {0};
    int pos_y[1001] = {0};
    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cin >> x >> y;
        pos_x[x]++;
        pos_y[y]++;
    }
    for (int i = 0; i < 1001; i++)
    {
        if (pos_x[i] == 1)
        {
            cout << i << ' ';
        }
    }
    for (int i = 0; i < 1001; i++)
    {
        if (pos_y[i] == 1)
        {
            cout << i;
        }
    }
    
}