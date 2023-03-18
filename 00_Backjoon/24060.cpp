#include <iostream>
using namespace std;

int* arr;
int* tmp;
int N,K;
int cnt = 0;
int result = -1;

void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right); // 분할
        merge(arr, left, mid, right); // 합병
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int t = 1;
    while (i <= mid && j <= right) // 왼쪽 배열이나 오른쪽 배열이 다 쓰일때까지
    {
        if (arr[i] <= arr[j]) tmp[t++] = arr[i++]; // 왼쪽배열과 오른쪽 배열에서 하나씩 꺼내와 비교  
        else tmp[t++] = arr[j++];
    }
    while (i <= mid) tmp[t++] = arr[i++]; // 왼쪽배열이 다쓰이지 못하고 남은 경우

    while (j <= right) tmp[t++] = arr[j++]; // 오른쪽 배열이 다쓰이지 못하고 남은 경우

    i = left;
    t = 1;
    while (i <= right) // 결과를 원래 배열에 다시 저장
    {
        if (K == ++cnt) result = tmp[t];
        arr[i++] = tmp[t++];
    }
}

int main()
{
    cin >> N >> K;
    arr = new int[N];
    tmp = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr, 0, N - 1);
    cout << result;

    delete[] arr;
    delete[] tmp;
}