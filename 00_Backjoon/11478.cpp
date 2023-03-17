#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    
    set <string> str_set;

    string s = "";
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            s += str[j]; // a, ab, aba, abab, ababc 순으로 증가하면서 삽입.
            str_set.insert(s); // set이므로 중복은 걸러준다.
        }
        s = ""; // 한바퀴 돌고 다음글자로 넘어갈때 초기화.
    }
    cout << str_set.size();
}