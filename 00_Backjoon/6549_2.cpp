#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        long long max_area = -1;
        for (int i = 1; i <= n; i++)
        {
            int min_height = 1000000000;
            for (int j = i; j <= n; j++) // O(n^2), i부터 j까지 가장 낮은 높이를 찾는다. j가 커질때마다 갱신해주기.
            {
                min_height = min(min_height, arr[j]);
                long long tmp = (j - i + 1) * min_height;
                max_area = max(max_area, tmp);
            }
        }
        cout << max_area << '\n';
    }
}