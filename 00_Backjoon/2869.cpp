#include <iostream>
using namespace std;
int main()
{
    int day; //A
    int night; //B
    int height; //V
    int time;

    cin >> day >> night >> height;
    time = (height - day) / (day - night);
    if ((height - day) % (day - night) != 0)
    {
        time++;
    }
    cout << time + 1;
}