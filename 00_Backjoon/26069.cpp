#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int cnt = 0;
    cin >> n;
    string str1, str2;
    set<string> Chong;
    Chong.insert("ChongChong");

    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2;
        if (Chong.count(str1) + Chong.count(str2))
        {
            Chong.insert(str1);
            Chong.insert(str2);
        }
    }
    cout << Chong.size();
}