#include <iostream>
using namespace std;
int main()
{
    int a,b; // a < b
    int tmp;
    cin >> a >> b;
    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            tmp = i;
        }
    }
    cout << tmp << '\n';
    tmp = b;
    while (1)
    {
        if (tmp % a == 0 && tmp % b == 0)
        {
            cout << tmp;
            break;
        }
        tmp++;
    }
}
