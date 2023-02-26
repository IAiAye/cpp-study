#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int alphabet[26] = {0};
    int val_max = -1;
    char ans;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] > 'Z')
        {
            s[i] -= 32;
        }
        alphabet[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] > val_max)
        {
            val_max = alphabet[i];
            ans = 'A' + i;
        }
        else if (alphabet[i] == val_max)
        {
            ans = '?';
        }
    }
    cout << ans;

    return 0;
}