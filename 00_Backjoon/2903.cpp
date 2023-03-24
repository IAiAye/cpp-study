#include <iostream>
#include <cmath>
using namespace std;

int dot(int n)
{
    if (n == 1) return 3;
    return 2 * dot(n - 1) - 1;
}

int main()
{
    int n;
    cin >> n;
    cout << (int)pow(dot(n), 2);
}