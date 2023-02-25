#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int index[30] = {0};
    int num;

    for (int i = 0; i < 28; i++)
    {
        cin >> num;
        index[num - 1] = 1;
    }
    for (int i = 0; i < 30; i++)
    {
        if (index[i] == 0)
        {
            cout << i + 1 << '\n';
        }
    }

    return 0;
}