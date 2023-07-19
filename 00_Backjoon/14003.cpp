#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000001

int n;
int arr[MAX];
int lis[MAX];
// arr 배열에서 a번째 수는 lis 배열에서 b번째에 저장됨. pos[a] = b;
int pos[MAX];

// lis에서 right보다 낮은 인덱스 중, target이 들어갈 자리 찾기
int binarySearch(int right, int target)
{
    // left는 항상 1이다.
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
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> arr[i];
    }
}

void Solution()
{
    lis[1] = arr[1];
    pos[1] = 1;
    int lisLength = 1;

    for (int i = 2; i <= n; i++)
    {
        if (lis[lisLength] < arr[i])
        {
            lis[++lisLength] = arr[i];
            pos[i] = lisLength;
        }
        else
        {
            // arr[i]보다 크거나 같은 인덱스 반환
            int idx = binarySearch(lisLength, arr[i]);
            lis[idx] = arr[i];
            pos[i] = idx;
        }
    }
    std::cout << lisLength << '\n';

    vector <int> ans;

    // pos 배열을 거꾸로 세어준다.
    for (int i = n; i >= 1; i--)
    {
        if (pos[i] == lisLength)
        {
            ans.push_back(arr[i]);
            if(--lisLength == 0) break;
        }
    }
    for (int i = 1; i <= ans.size(); i++)
    {
        std::cout << ans[ans.size() - i] << ' ';
    }
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