#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num; // <= 100
    string str; // 소문자, 최대 100자
    int cnt = 0;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int alpha[26] = {0};
        int cnt_alpha = 0;
        int cnt_diff = 1;

        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            if (alpha[str[j] - 'a'] == 0) //어떤 알파벳이 있는지 체크.
            {
                alpha[str[j] - 'a'] += 1;
                cnt_alpha++;
            }
            if (str[j] != str[j + 1] && j != str.length() - 1) // 앞뒤가 다를때마다  체크.
            {
                cnt_diff++;
            }
        }
        if (cnt_alpha == cnt_diff)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}