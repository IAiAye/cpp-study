#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL);
	cin.sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    queue <int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "push")
        {
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
        else if (s == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            } else cout << -1 << '\n';
        }
        else if (s == "size")
        {
            cout << q.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (s == "front")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
            } else cout << -1 << '\n';
        }
        else if (s == "back")
        {
            if (!q.empty())
            {
                cout << q.back() << '\n';
            } else cout << -1 << '\n';
        }
    }
}