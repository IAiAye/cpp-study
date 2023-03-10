#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool compare (string a, string b)
{
    if (a.length() < b.length())
    {
        return true;
    }
    else if (a.length() > b.length())
    {
        return false;
    }
    return a < b;
}
int main()
{
    vector<string> str_list;
    int num;
    string str;
    bool overlap = false;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> str;
        for (int j = 0; j < str_list.size(); j++)
        {
            if (str_list[j] == str)
            {
                overlap = true;
                break;
            }
        }
        if (!overlap)
        {
            str_list.push_back(str);
        }
        overlap = false;
    }
    sort(str_list.begin(), str_list.end(),compare);
    for (int i = 0; i < str_list.size(); i++)
    {
        cout << str_list[i] << '\n';
    }
}