#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int arr[1000] = {0};
    int lis[1000] = {0};
    int lds[1000] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) // i의 lis 구하기
    {
        lis[i] = 1;
        int lis_max = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && lis[j] > lis_max)
            {
                lis_max = lis[j];
            }
        }
        lis[i] = lis_max + 1;
    }
    for (int i = n - 1; i >= 0; i--) // i의 lds 구하기
    {
        lds[i] = 1;
        int lds_max = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i] && lds[j] > lds_max)
            {
                lds_max = lds[j];
            }
        }
        lds[i] = lds_max + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if ((lis[i] + lds[i] - 1) > ans)
        {
            ans = lis[i] + lds[i] - 1;
        }
    }
    cout << ans;
    

    return 0;
}