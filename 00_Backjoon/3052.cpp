#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int count = 0;
    int num;
    int arr[42] = {0};

    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        if (arr[num % 42] == 0)
        {
            arr[num % 42] += 1;
            count += 1;
        }
    }
    cout << count;
    return 0;
}