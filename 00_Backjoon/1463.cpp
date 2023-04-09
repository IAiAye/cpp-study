#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[1000001] = {0};
    int n;
    cin >> n;

    arr[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        int min_value = 1000000;

        if (i % 3 == 0)
        {
            min_value = min(arr[i / 3], min_value);    
        }
        if (i % 2 == 0)
        {
            min_value = min(arr[i / 2], min_value);
        }
        min_value = min(arr[i - 1], min_value);
        arr[i] = min_value + 1;
    }
    cout << arr[n];

    return 0;
}