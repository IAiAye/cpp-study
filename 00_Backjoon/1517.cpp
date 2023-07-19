#include <iostream>
using namespace std;
#define MAX 500001

int n;
int arr[MAX];
int sorted[MAX];

long long swapCnt[MAX];
long long psum;

// list[left ~ mid], list[mid + 1 ~ right]을 합치는 과정
// 왼쪽과 오른쪽 배열은 각각 정렬이 되어있다.
// 따라서 스왑이 일어나는 것은 오른쪽 배열에서 왼쪽 배열보다 작은 수가 있는 만큼 일어난다.
void Merge(int left, int mid, int right)
{
    int leftListIdx = left;
    int rightListIdx = mid + 1;
    int sortedIdx = left;

    // 모든 카운트를 0으로 초기화 시켜준다.
    for (int i = left; i <= right; i++)
        swapCnt[i] = 0;
    

    while (leftListIdx <= mid && rightListIdx <= right)
    {
        if (arr[leftListIdx] <= arr[rightListIdx]) sorted[sortedIdx++] = arr[leftListIdx++];
        else 
        {
            sorted[sortedIdx++] = arr[rightListIdx++];
            // 왼쪽 배열의 한 숫자보다 오른 쪽 배열에서 크기가 작은 수의 숫자를 세준다.
            // 다만 leftListIdx가 넘어간 후에는 이전에서 이미 세줬으므로 이후에 누적합으로 계산한다.
            swapCnt[leftListIdx]++;
        }

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


    long long sum = 0;
    for (int i = left; i <= mid; i++)
    {
        // 누적합으로 계산
        sum += swapCnt[i];
        psum += sum;
    }
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
    cout << psum << '\n';
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