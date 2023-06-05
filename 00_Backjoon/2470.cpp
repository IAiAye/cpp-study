#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <int> phs;

void Input()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        phs.push_back(temp);
    }
}

void Solution()
{
    sort(phs.begin(), phs.end());
    
    int start = 0;
    int end = n - 1;

    // // 산성 용액이나 알칼리성 용액으로만 주어진 경우
    // if (phs[start] * phs[end] >= 0)
    // {
    //     // 산성일 경우
    //     if (phs[start] < 0)
    //     {
    //         // 0에 가까운 두 개의 수 출력
    //         std::cout << phs[end - 1] << ' ' << phs[end] << '\n';
    //         return;
    //     }
    //     // 알칼리성일 경우
    //     else
    //     {
    //         // 0에 가까운 두 개의 수 출력
    //         std::cout << phs[start] << ' ' << phs[start + 1] << '\n';
    //         return;
    //     }
    // }

    int gap = 2000000001;
    pair <int, int> ansPair = {0, 0};
    while (start != end)
    {
        int sum = phs[start] + phs[end];

        // 합이 정확이 0인 경우
        if (sum == 0)
        {
            std::cout << phs[start] << ' ' << phs[end] << '\n';
            return; 
        }

        if (abs(sum) < gap)
        {
            gap = abs(sum);
            ansPair = {phs[start], phs[end]};
        }
        // 합이 양수일땐 end쪽을 당기고, 음수일땐 start쪽을 당긴다.
        if (sum > 0) end--;
        else start++;
    }
    
    std::cout << ansPair.first << ' ' << ansPair.second << '\n';
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