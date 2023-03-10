#include <iostream>
#include <string>
using namespace std;
int main()
{
    string num;
    int arr[10] = {0};
    cin >> num;

    for (int i = 0; i < num.length(); i++)
    {
        arr[num[i] - '0']++;
    }
    for (int j = 9; j >= 0; j--)
    {
        while(arr[j])
        {
            cout << j;
            arr[j]--;
        }
    }
}