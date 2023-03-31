#include <iostream>
#include <string>
#include <set>
#include <cmath>
using namespace std;
int main()
{
    set <string> m;
    string s1, s2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        if (s2 == "enter") m.insert(s1);
        else if (s2 == "leave") m.erase(s1);
    }
    for (auto iter = m.rbegin(); iter != m.rend(); iter++) cout << *iter << '\n';
}