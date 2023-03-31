#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    stack <int> s;
    vector <char> v;
    cin >> n;
    int cnt = 1;
    bool flag = true;

    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        while(1)
        {
            if (!s.empty() && tmp == s.top())
            {
                s.pop();
                v.push_back('-');
                break;
            }
            else
            {
                s.push(cnt);
                v.push_back('+');
                cnt++;
            }
            if (cnt > n + 1)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j] << '\n';
        }
    } else cout << "NO";
}