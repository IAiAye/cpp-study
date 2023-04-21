#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[2187][2187];
int cnt_negative;
int cnt_zero;
int cnt_positive;

void paper(int x1, int y1, int x2, int y2)
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
        if (first_num == -1) cnt_negative++;
        else if (first_num == 0) cnt_zero++;
        else cnt_positive++;
        return;
    }
    else
    {
        paper(x1, y1, (2 * x1 + x2) / 3, (2 * y1 + y2) / 3);
        paper(x1, (2 * y1 + y2) / 3, (2 * x1 + x2) / 3, (y1 + 2 * y2) / 3);
        paper(x1, (y1 + 2 * y2) / 3, (2 * x1 + x2) / 3, y2);

        paper((2 * x1 + x2) / 3, y1, (x1 + 2 * x2) / 3, (2 * y1 + y2) / 3);
        paper((2 * x1 + x2) / 3, (2 * y1 + y2) / 3, (x1 + 2 * x2) / 3, (y1 + 2 * y2) / 3);
        paper((2 * x1 + x2) / 3, (y1 + 2 * y2) / 3, (x1 + 2 * x2) / 3, y2);

        paper((x1 + 2 * x2) / 3, y1, x2, (2 * y1 + y2) / 3);
        paper((x1 + 2 * x2) / 3, (2 * y1 + y2) / 3, x2, (y1 + 2 * y2) / 3);
        paper((x1 + 2 * x2) / 3, (y1 + 2 * y2) / 3, x2, y2);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    paper(0, 0, n, n);

    cout << cnt_negative << '\n' << cnt_zero << '\n' << cnt_positive << '\n';
    return 0;
}