#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int MaxValue = 0;
    int pos = 0;
    int num;

    for (int i = 0; i < 9; i++)
    {
        cin >> num;
        if (num > MaxValue)
        {
            MaxValue = num;
            pos = i;
        }
    }
    cout << MaxValue << "\n" << pos + 1;

    return 0;
}