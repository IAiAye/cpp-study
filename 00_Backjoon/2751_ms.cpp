#include <iostream>
using namespace std;
#define MAX 1000001

int n;
int arr[MAX];
int sorted[MAX];

// list[left ~ mid], list[mid + 1 ~ right]을 합치는 과정
void Merge(int left, int mid, int right)
{
    int leftListIdx = left;
    int rightListIdx = mid + 1;
    int sortedIdx = left;

    while (leftListIdx <= mid && rightListIdx <= right)
    {
        if (arr[leftListIdx] <= arr[rightListIdx]) sorted[sortedIdx++] = arr[leftListIdx++];
        else sorted[sortedIdx++] = arr[rightListIdx++];
    }
    // 탈출하면 왼쪽 배열이나 오른쪽 배열이 끝까지 간 것이다.
    // 오른쪽 배열이 남아있을 경우
    while (rightListIdx <= right)
        sorted[sortedIdx++] = arr[rightListIdx++];
    // 왼쪽 배열이 남아있을 경우
    while (leftListIdx <= mid)
        sorted[sortedIdx++] = arr[leftListIdx++];

    // 다시 옮겨주기
    for (int i = left; i <= right; i++)
        arr[i] = sorted[i];
}

void MergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        // 크기가 1이 될때까지 재귀 반복한다.
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
    
}

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];        
}

void Solution()
{
    MergeSort(1, n);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << '\n';
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