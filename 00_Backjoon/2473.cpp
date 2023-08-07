#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> sols;

void Input()
{
    // n = 6;
    // sols.push_back(-104336608);
    // sols.push_back(239510944);
    // sols.push_back(997686289);
    // sols.push_back(627058077);
    // sols.push_back(722156401);
    // sols.push_back(-942278495);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        sols.push_back(tmp);
    }
}

void Solution()
{
    /*
    용액을 정렬하고,
    왼쪽 오른쪽 포인터 잡고
    그 안에서 루프 돌면서 가장 0에 가까운값 찾아보고
    좌우로 땡기기
    */
   sort(sols.begin(),sols.end());
   long long ans = 3000000001LL;
   int first = 0;
   int second = 1;
   int third = 2;

   for (int i = 0; i <= n - 2; i++)
   {
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            long long sum = static_cast<long long>(sols[i]) + sols[left] + sols[right];
            
            if (abs(sum) < ans)
            {
                ans = abs(sum);
                first = i;
                second = left;
                third = right;
            }
            if (sum == 0)
                break;
            else if (sum > 0)
                right--;
            else
                left++;
        }
        if (ans == 0)
            break;
   }
   
    cout << sols[first] << ' ' << sols[second] << ' ' << sols[third] << '\n';
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