#include <iostream>

using namespace std;

int arr[1000000], tmp_arr[1000000];

long long count_inv(int start, int end) 
{
    if (start == end) 
        return 0;

    int mid = (start + end) / 2;
    long long ret = count_inv(start, mid) + count_inv(mid + 1, end);

    for (int i = start; i <= end; i++) 
        tmp_arr[i] = arr[i];

    int tmp = 0;
    int index = start;

    int l_start = start;
    int l_end = mid;

    int r_start = mid + 1;
    int r_end = end;

    while (l_start <= l_end && r_start <= r_end) 
    {
        if (tmp_arr[l_start] > tmp_arr[r_start]) 
        {
            arr[index++] = tmp_arr[r_start++];
            tmp++;
        } 
        else 
        {
            arr[index++] = tmp_arr[l_start++];
            ret += tmp;
        }
    }
    while (l_start <= l_end) 
    {
        arr[index++] = tmp_arr[l_start++];
        ret += tmp;
    }
    while (r_start <= r_end) arr[index++] = tmp_arr[r_start++];

    return ret;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    cout << count_inv(0, n - 1) << '\n';

    return 0;
}
