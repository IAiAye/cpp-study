#include <iostream>
#include <string>
using namespace std;

int alphabet[26][200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (j == s[i - 1] -'a')
            {
                alphabet[j][i] = alphabet[j][i - 1] + 1;
                
            } else alphabet[j][i] = alphabet[j][i - 1];
        }
    }
    
    int q;
    cin >> q;
    char char_q;
    int start, end;

    for (int i = 0; i < q; i++)
    {
        cin >> char_q >> start >> end;
        cout << alphabet[char_q - 'a'][end + 1] - alphabet[char_q - 'a'][start] << '\n';
    }
    
    return 0;
}
