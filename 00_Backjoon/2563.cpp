#include <iostream>
using namespace std;
int main()
{
    int paper[100][100] = {0};
    int num, pos_x, pos_y;
    int area = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> pos_x >> pos_y;
        for (int j = pos_x; j < pos_x + 10; j++)
        {
            for (int k = pos_y; k < pos_y + 10; k++)
            {
                if (paper[j][k] == 0)
                {
                    paper[j][k]++;
                    area += 1;
                }
            }
        }
    }
    cout << area;

}