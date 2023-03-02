#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int i = 0;
    int sum = 0;
    while (num > sum)
    {
        i++;
        sum += i;
    }
    if (i % 2 == 0)
    {
        cout << i - (sum - num) << "/" << (sum - num) + 1;
    }
    else
    {
        cout << (sum - num) + 1 << "/" << i - (sum - num);
    }
}