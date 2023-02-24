#include <iostream>

using namespace std;

int main()
{
    int X;
    int N;
    int sum = 0;
    int price, count;
    cin >> X;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> price >> count;
        sum += price * count;
    }
    if (X == sum)
    {
        cout  << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}