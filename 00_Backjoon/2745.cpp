#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string s;
    int b;
    cin >> s >> b;
    int result = 0;
    int tmp;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[s.length() - i - 1] > 64) tmp = s[s.length() - i - 1] - 55;
        else tmp = s[s.length() - i - 1] - 48;
        result += pow(b, i) * tmp; 
    }
    cout << result;
}