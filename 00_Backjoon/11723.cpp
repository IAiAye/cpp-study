#include <iostream>
#include <string>
using namespace std;

bool s[21];

int m;
string str;

void Input()
{
    cin >> m;
}

void Solution()
{
    while (m--)
    {
        cin >> str;
        if (str == "add")
        {
            int num;
            cin >> num;
            s[num] = true;
        }
        else if (str == "remove")
        {
            int num;
            cin >> num;
            s[num] = false;
        }
        else if (str == "check")
        {
            int num;
            cin >> num;
            if (s[num]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (str == "toggle")
        {
            int num;
            cin >> num;
            s[num] = !s[num];
        }
        else if (str == "all")
        {
            for (int i = 1; i <= 20; i++)
            {
                s[i] = true;
            }
        }
        else if (str == "empty")
        {
            for (int i = 1; i <= 20; i++)
            {
                s[i] = false;
            }
        }
    }
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}