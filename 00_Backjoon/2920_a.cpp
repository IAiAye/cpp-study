#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[8];

void Input()
{
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }
    
}

void Solution()
{
    bool flag = true;
    if (arr[0] == 1)
    {
        for (int i = 1; i < 8; i++)
        {
            if (arr[i] != i + 1)
            {
                flag = false;
                break;
            }
        }
        if  (flag)
            cout << "ascending" << '\n';
    }
    else if (arr[0] == 8)
    {
        for (int i = 1; i < 8; i++)
        {
            if (arr[i] != 8 - i)
            {
                flag = false;
                break;
            }
        }
        if  (flag)
            cout << "descending" << '\n';
    }
    else
        flag = false;
    if (!flag)
        cout << "mixed" << '\n';
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