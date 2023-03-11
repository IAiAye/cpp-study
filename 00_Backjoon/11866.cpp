#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> arr1;
    vector <int> arr2;
    for (int i = 1; i <= n; i++)
    {
        arr1.push_back(i);
    }
    int cnt = 0;
    int k_cnt = 0;
    int count = 0;
    while (1)
    {
        if (arr1[cnt] != 0)
        {
            k_cnt++;
            if (k_cnt == k)
            {
                k_cnt = 0;
                arr2.push_back(arr1[cnt]);
                arr1[cnt] = 0;
                count++;
            }
        }
        cnt++;
        if (cnt >= n)
        {
            cnt -= n;
        }
        if (count == n)
        {
            break;
        }
    }
    cout << '<';
    cout << arr2[0];
    for (int i = 1; i < n; i++)
    {
        cout << ", " << arr2[i];
    }
    cout << '>';
}
