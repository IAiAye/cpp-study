#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int queue[10000];

void Input()
{
    cin >> n;
}

void Solution()
{
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        
        if (cmd == "push")
        {
            int num;
            cin >> num;
            queue[size++] = num;
        }
        else if (cmd == "pop")
        {
            if (size != 0)
            {
                cout << queue[0] << '\n';
                size--;
                for (int i = 0; i < size; i++)
                {
                    queue[i] = queue[i + 1];
                }
            }
            else cout << -1 << '\n';
        }
        else if (cmd == "size")
        {
            cout << size << '\n';
        }
        else if (cmd == "empty")
        {
            if (size == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "front")
        {
            if (size != 0) cout << queue[0] << '\n';
            else cout << -1 << '\n';
        }
        else if (cmd == "back")
        {
            if (size != 0) cout << queue[size - 1] << '\n';
            else cout << -1 << '\n';
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