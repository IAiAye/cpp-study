#include <iostream>
using namespace std;
typedef long long ll;

int main() 
{
    int a1, a0;
    int c, n0;
    cin >> a1 >> a0;
    cin >> c >> n0;

    if (c >= a1 && c * n0 >= a1 * n0 + a0)
    {
        cout << 1;
    }
    else cout << 0;
}