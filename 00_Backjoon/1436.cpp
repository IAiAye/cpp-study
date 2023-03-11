#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int order;
    int number = 665;
    int cnt = 0;
    cin >> order;

    while (1)
    {
        string s = to_string(number);
        for (int i = 0; i < s.length() - 2; i++)
        {
            if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6')
            {
                cnt++;
                break;
            }
        }
        if (cnt == order)
        {
            cout << number;
            return 0;
        } else number++;
    }
}
