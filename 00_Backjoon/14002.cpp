#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[1001];
int LIS[1001];
vector <int> sub[1001];

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
    for (int i = 1; i <= n; i++)
    {
        // 최소 길이는 1이기 때문에
        LIS[i] = 1;
        sub[i].push_back(arr[i]);

        // 앞에 있는 인덱스 확인
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (LIS[i] < LIS[j] + 1)
                {
                    LIS[i] = LIS[j] + 1;
                    sub[i].assign(sub[j].begin(), sub[j].end());
                    sub[i].push_back(arr[i]);
                }
            }
        }
    }
    
    int bIdx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (LIS[bIdx] < LIS[i])
        {
            bIdx = i;
        }
    }
    
    std::cout << LIS[bIdx] << '\n';
    for (int i = 0; i < LIS[bIdx]; i++)
    {
        std::cout << sub[bIdx][i] << ' ';
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