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
            for (int j = i; j <= n; j++)
            {
                int min_height = 1000000000;
                for (int k = i; k <= j; k++) // O(n^3), i부터 j까지 중 가장 낮은 높이 찾기
                {
                    min_height = min(min_height, arr[k]);
                }
                long long tmp = (j - i + 1) * min_height;
                max_area = max(max_area, tmp);
            }
        }
        cout << max_area << '\n';
    }
}