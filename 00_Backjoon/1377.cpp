#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[500001];
int lis[500001];

int binarySearch(int right, int target)
{
    int left = 1;
    while (left != right)
    {
        int mid = (left + right) / 2;

        if (target <= lis[mid]) right = mid;
        else left = mid + 1;
    }
    return right;
}

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
}

void Solution()
{
    
    lis[1] = arr[1];
    int lisLength = 1;

    for (int i = 2; i <= N; i++)
    {
        // 같은 크기도 수열에 포함시켜준다.
        if (lis[lisLength] <= arr[i])
        {
            lis[++lisLength] = arr[i];
        }
        else
        {
            // arr[i]보다 크거나 같은 인덱스 반환
            int idx = binarySearch(lisLength, arr[i]);
            lis[idx] = arr[i];
        }
    }
    // 최장 거리 수열이 있는 만큼은 연산을 안해줘도 되기때문에 빼주면 된다.
    cout << N - lisLength + 1 << '\n';
    
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