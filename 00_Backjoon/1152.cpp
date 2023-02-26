#include <iostream>
#include <string>

using namespace std;

int main()
{
    int from, to = 0;
    int count = 0;

    string s;
    getline(cin, s);

    if (s.empty()) // 공백만 있을 경우 고려.
    {
        cout << count;
        return 0;
    }
    count = 1;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            from = i;
            break;
        }
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            to = i;
            break;
        }
    }
    for (int i = from; i < to; i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    cout << count << '\n';

    return 0;
}