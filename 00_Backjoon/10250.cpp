#include <iostream>
using namespace std;
int main()
{
    int floor; //H
    int room; //W
    int test_num; //T
    int num; //N
    int num_x;
    cin >> test_num;
    for (int i = 0; i < test_num; i++)
    {
        cin >> floor >> room >> num;
        num_x = num / floor + 1;
        if (num % floor == 0)
        {
            num_x--;
        }
        cout << num - (num_x - 1) * floor;

        if (num_x < 10)
        {
            cout << '0' << num_x;
        }
        else cout << num_x;
        cout << '\n';
    }
}