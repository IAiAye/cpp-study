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
    string str;
    set<string> chat;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "ENTER")
        {
            cnt += chat.size();
            chat.erase(chat.begin(), chat.end());
            continue;
        }
        chat.insert(str);
    }
    cnt += chat.size();
    cout << cnt << '\n';
}