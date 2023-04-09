#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector <int> sum(500);
    vector <int> sum_tmp(500);
    int tmp1, tmp2;
    cin >> sum[0];
    for (int i = 2; i <= n; i++)
    {
        cin >> tmp1;
        tmp2 = sum[0];
        sum_tmp[0] = tmp1 + tmp2;
        for (int j = 1; j < i - 1; j++)
        {
            cin >> tmp1;
            tmp2 = max(sum[j - 1], sum[j]);
            sum_tmp[j] = tmp1 + tmp2;
        }
        cin >> tmp1;
        tmp2 = sum[i - 2];
        sum_tmp[i - 1] = tmp1 + tmp2;
        
        sum = sum_tmp;
    }
    sort(sum.begin(), sum.end());
    cout << *sum.rbegin();

    return 0;
}
