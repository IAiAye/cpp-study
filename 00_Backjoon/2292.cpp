#include <iostream>
using namespace std;
int main()
{
    int num;
    int count = 1;
    int i = 1;
    cin >> num;
    //1 7 19 37 61
    while (num > count)
    {
        count += 6 * i;
        i++;
    }
    cout << i;
}