#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int steps[301];
    int sum[301] = {0};
    
    for (int i = 1; i <= n; i++) // i 층
    {
        cin >> steps[i];
    }
    sum[1] = steps[1];
    sum[2] = steps[1] + steps[2];
    sum[3] = max(steps[1] + steps[3], steps[2] + steps[3]);

    for (int i = 4; i <= n; i++) 
    {
        if (sum[i - 2] > sum[i - 3] + steps[i - 1])
        {
            sum[i] = sum[i - 2] + steps[i]; // i 바로 전에서 한 칸만 뛰었을때.
        }
        else
        {
            sum[i] = sum[i - 3] + steps[i - 1] + steps[i]; // i 전에 한칸을 포함하고 그전 칸을 뛰었을때. 
        }
    }
    
    cout << sum[n] << '\n';

    return 0;
}