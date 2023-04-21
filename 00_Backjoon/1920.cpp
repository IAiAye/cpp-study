#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> nums;

void find(int left, int right, int num)
{
    if (left == right)
    {
        if (nums[left] == num) cout << 1 << '\n';
        else cout << 0 << '\n';
        return;
    }
    
    int mid = (left + right) / 2;
    // 이진 탐색에서 왼쪽에 있을때.
    if (num < nums[mid]) find(left, mid, num);
    // 이진 탐색에서 오른쪽에 있을때.
    else if (num > nums[mid]) find(mid + 1, right, num);
    else cout << 1 << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        find(0, n - 1, tmp);
    }
}