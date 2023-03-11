#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    int tmp;
    int sum = -1;
    cin >> n >> m;
    vector <int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > sum)
                {
                    sum = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }
    cout << sum;
}