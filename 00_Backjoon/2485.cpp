#include <iostream>
#include <vector>
using namespace std;

int tmp, gcd_value;

void gcd(int a, int b)
{
    if (a == 0)
    {
        gcd_value = b;
    }
    
    if (a > b) // a < b 가 되도록.
    {
        tmp = b;
        b = a;
        a = tmp;
    }
    if (a != 0)
    {
        tmp = a;
        a = b % a;
        b = tmp;
        gcd(a , b);
    }
}

int main()
{
    int n;
    vector <int> pos;
    vector <int> diff;
    cin >> n;
    cin >> tmp;
    pos.push_back(tmp);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        pos.push_back(tmp);
        diff.push_back(pos[i + 1] - pos[i]);
    }
    gcd(diff[0], diff[1]);
    for (int i = 2; i < n - 1; i++)
    {
        gcd(gcd_value, diff[i]);
    }
    cout << ( pos[n - 1] - pos[0] ) / gcd_value - n + 1 ;
}