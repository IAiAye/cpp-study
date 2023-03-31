#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int s, b;
    char tmp;
    int i = 0;
    vector <char>number;
    cin >> s >> b;

    while (s / (int)pow(b,i)) { i++; } // 자리수 알아내기

    for (int j = i - 1; j != -1; j--)
    {
        if (s / (int)pow(b, j) > 9) tmp = s / (int)pow(b, j) + 55;
        else tmp = s / (int)pow(b, j) + 48;
        s %= (int)pow(b, j);
        cout << tmp;
    }
}