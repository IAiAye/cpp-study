#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num;

void Input()
{
    cin >> num;
}

void Solution()
{
    int cnt = num.size();
    while (true)
    {
        char maxC = 0;
        int maxIdx = -1;
        // 정렬될수록 뒤로 범위가 줄어들면서 정렬
        for (int i = num.size() - cnt; i < num.size(); i++)
        {
            if (maxC < num[i])
            {
                maxC = num[i];
                maxIdx = i;
            }
        }
        if (maxIdx == -1) break;
        swap(num[maxIdx], num[num.size() - cnt]);
        cnt--;
    }
    cout << num << '\n';
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