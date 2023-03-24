#include <iostream>
#include <cmath>
using namespace std;

void coin(int num)
{
    cout << num / 25 << ' ';
    num = num % 25;
    cout << num / 10 << ' ';
    num = num % 10;
    cout << num / 5 << ' ';
    num = num % 5;
    cout << num << ' ';
}

int main()
{
    int t;
    int tmp;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> tmp;
        coin(tmp);
        cout << '\n';
    }
}