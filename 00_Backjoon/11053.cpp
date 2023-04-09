#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int arr[1000] = {0};
    int DP[1000] = {0};

    for (int i = 0; i < n; i++) // 입력
    {
        cin >> arr[i];
    }

    int total_max = 1; // 최소 1이므로 1에서  시작

    for (int i = 0; i < n; i++)
    {
        DP[i] = 1;
        int max_value = 0;
        for (int j = 0; j < i; j++)
        {
            if ((arr[j] < arr[i]) && (DP[j] > max_value))
            {
                max_value = DP[j];
            }
        }
        DP[i] = max_value + 1;
        if (DP[i] > total_max)
        {
            total_max = DP[i];
        }
    }
    cout << total_max;

    return 0;
}