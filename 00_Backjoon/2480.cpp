#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int prize;
    cin >> a >> b >> c;

    if (a == b && b == c)
    {
        prize = 10000 + a * 1000;
        cout << prize << endl;
        return 0;
    }
    if (a == b)
    {
        prize = 1000 + a * 100;
        cout << prize << endl;
        return 0;
    }
    if (c == b)
    {
        prize = 1000 + b * 100;
        cout << prize << endl;
        return 0;
    }
    if (a == c)
    {
        prize = 1000 + a * 100;
        cout << prize << endl;
        return 0;
    }
    if (a > b && a > c)
    {
        prize = a * 100;
        cout << prize << endl;
        return 0;
    }
    if (b > c)
    {
        prize = b * 100;
        cout << prize << endl;
        return 0;
    }
    prize = c * 100;
    cout << prize << endl;
    return 0;
}