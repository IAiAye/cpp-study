#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num;
    while (1)
    {
        bool is_fel = true;
        cin >> num;
        if (num == 0)
        {
            return 0;
        }
        string s = to_string(num);
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                is_fel = false;
            }
        }
        if (is_fel)
        {
            cout << "yes" << '\n';
        } else cout << "no" << '\n';
    }
}
