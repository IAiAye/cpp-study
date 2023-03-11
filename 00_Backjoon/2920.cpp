#include <iostream>
using namespace std;
int main()
{
    bool straight = true;
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }
    if (arr[0] == 1)
    {
        for (int i = 0; i < 8; i++)
        {
            if (arr[i] != i + 1)
            {
                straight = false;
                break;
            }
        }
        if (straight)
        {
            cout << "ascending";
            return 0;
        }
        else
        {
            cout << "mixed";
            return 0;
        }
    }
    else if (arr[0] == 8)
    {
        for (int i = 0; i < 8; i++)
        {
            if (arr[i] != 8 - i)
            {
                straight = false;
                break;
            }
        }
        if (straight)
        {
            cout << "descending";
            return 0;
        }
        else
        {
            cout << "mixed";
            return 0;
        }
    }
    else
    {
        cout << "mixed";
        return 0;
    }
}