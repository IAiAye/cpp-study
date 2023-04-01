#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
    cin.tie(NULL);
	cin.sync_with_stdio(false);

    deque <int> d;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int tmp;
        if (s == "push_front")
        {
            cin >> tmp;
            d.push_front(tmp);
        }
        if (s == "push_back")
        {
            cin >> tmp;
            d.push_back(tmp);
        }
        if (s == "pop_front")
        {
            if (!d.empty())
            {
                cout << d.front() << '\n';
                d.pop_front();
            } else cout << -1 << '\n';
        }
        if (s == "pop_back")
        {
            if (!d.empty())
            {
                cout << d.back() << '\n';
                d.pop_back();
            } else cout << -1 << '\n';
        }
        if (s == "size")
        {
            cout << d.size() << '\n';
        }
        if (s == "empty")
        {
            cout << d.empty() << '\n';
        }
        if (s == "front")
        {
            if (!d.empty())
            {
                cout << d.front() << '\n';
            } else cout << -1 << '\n';
        }
        if (s == "back")
        {
            if (!d.empty())
            {
                cout << d.back() << '\n';
            } else cout << -1 << '\n';
        }
    }
    return 0;
}