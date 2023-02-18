#include <iostream>

using namespace std;

int main()
{
    int hour, min;
    cin >> hour >> min;

    min -= 45;
    if (min < 0)
    {
        hour -= 1;
        min += 60;
        if (hour == -1)
        {
            hour = 23;
        }
    }
    cout << hour << " " << min << endl;
    return 0;
}