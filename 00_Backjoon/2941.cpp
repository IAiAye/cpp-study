#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    string str_a = "a";
    int count = str.length();
    string alpha[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (str.find(alpha[i]) < str.length() && str.find(alpha[i]) >= 0)
            {
                if (i == 2)
                {
                    str.replace(str.find(alpha[i]),3,str_a);
                    count--;
                    count--;
                }
                else
                {
                    str.replace(str.find(alpha[i]),2,str_a);
                    count--;
                }
            }
        }
    }
    cout << count;
    return 0;
}