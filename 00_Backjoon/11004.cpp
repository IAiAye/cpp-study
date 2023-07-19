#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector <int> arr;

int Partition(int start, int end)
{
    if (start + 1 == end)
    {
        if (arr[start] > arr[end]) swap(arr[start], arr[end]);
        return end;
    }

    int mid = (start + end) / 2;
    int pivot = arr[mid];
    // pivot을 왼쪽으로 옮겨놓기
    swap(arr[start], arr[mid]);
    int left = start + 1;
    int right = end;

    while (left <= right)
    {
        while (pivot < arr[right] && right >= start)
        {
            right--;
        }
        while (pivot > arr[left] && left <= end)
        {
            left++;
        }
        
        if (left <= right) swap(arr[left++], arr[right--]);
    }
    arr[start] = arr[right];
    arr[right] = pivot;
    return right;
}

void QuickSelect(int start, int end, int k)
{
    int pivotIdx = Partition(start, end);
    // pivot의 위치는 정렬되어있다.
    if (pivotIdx == k) return;
    // 퀵정렬과는 다르게 절반씩만 탐색한다.
    if (k < pivotIdx) QuickSelect(start, pivotIdx - 1, k);
    else QuickSelect(pivotIdx + 1, end, k);
}

void Input()
{
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Solution()
{
    QuickSelect(0, n - 1, k - 1);
    cout << arr[k - 1] << '\n';
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}