#include <iostream>
#include <string>
using namespace std;

int arr[64][64];

void quad_tree(int x1, int y1, int x2, int y2)
{
    bool flag = true;
    int first_num = arr[x1][y1];
    for (int i = x1; i < x2; i++)
    {
        for (int j = y1; j < y2; j++)
        {
            if (first_num != arr[i][j])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    if (flag)
    {   
        if (first_num)
        {
            cout << 1;
        } else cout << 0;
        return;
    }
    else
    {
        cout << '(';
        quad_tree(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
        quad_tree(x1, (y1 + y2) / 2, (x1 + x2) / 2, y2);
        quad_tree((x1 + x2) / 2, y1, x2, (y1 + y2) / 2);
        quad_tree((x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
        cout << ')';
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = s[j] - 48;
        }
    }
    quad_tree(0,0, n, n);

    return 0;
}
