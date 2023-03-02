#include <iostream>
using namespace std;
int main()
{
    int weight; //N
    int num_5;
    int num_3;

    cin >> weight;

    for (int i = weight / 5; i >= 0 ; i--)
    {
        num_5 = i;
        num_3 = ( weight - i * 5 ) / 3;
        if (weight - num_5 * 5 - num_3 * 3 == 0)
        {
            cout << num_5 + num_3;
            return 0;
        }
    }
    cout << "-1";
}