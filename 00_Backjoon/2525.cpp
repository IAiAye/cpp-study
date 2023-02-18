#include <iostream>

using namespace std;

int main()
{
    int hour, min;
    int cook_time;
    cin >> hour >> min >> cook_time;

    min += cook_time;
    while (min > 59)
    {
        hour += 1;
        min -= 60;
        if (hour == 24)
        {
            hour = 0;
        }
    }
    cout << hour << " " << min << endl;
    return 0;
}