#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector <int> num;
    vector <char> oper;

    string s;
    string tmp = "";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            tmp += s[i];
        }
        else
        {
            oper.push_back(s[i]);
            num.push_back(stoi(tmp));
            tmp = "";
        }
    }
    num.push_back(stoi(tmp)); // 마지막 숫자 추가.

    int ans = num[0];
    bool flag = false;
    for (int i = 0; i < oper.size(); i++)
    {
        if (oper[i] == '-')
        {
            flag = true;
        }
        if (oper[i] == '+' && flag)
        {
            oper[i] = '-';
        }
        if (oper[i] == '-') ans -= num[i + 1];
        else ans += num[i + 1];
    }
    cout << ans << '\n';
    
    return 0;
}
