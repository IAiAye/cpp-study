#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

int tc;

void Input()
{
    cin >> tc;
}

void Solution()
{
    while (tc--)
    {
        int k;
        cin >> k;

        multiset<int> ms;
        
        while (k--)
        {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I')
            {
                ms.insert(num);
            }
            else if (!ms.empty())
            {
                if (num == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
                else
                {
                    ms.erase(ms.begin());
                }
            }
        }
        if (ms.empty())
            cout << "EMPTY" << '\n';
        else
        {
            auto iter = ms.end();
            iter--;
            cout << *iter << ' ' << *(ms.begin()) << '\n';
        }

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