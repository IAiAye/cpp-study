#include <iostream>
using namespace std;

int N, r, c;

void Input()
{
    cin >> N >> r >> c;
}

void Solution()
{
    long long num = 0;
    while (N)
    {
        long long twoExp = (1 << (N - 1));
        //cout << twoExp << ' ' << r / twoExp << ' ' << c / twoExp << '\n';
        long long y = r / twoExp;
        long long x = c / twoExp;
        N--;

        if (y == 0)
        {
            if (x == 0)
            {
            }
            else
            {
                num += twoExp * twoExp;
                c -= twoExp;
            }
        }
        else
        {
            if (x == 0)
            {
                num += twoExp * twoExp * 2;
                r -= twoExp;
            }
            else
            {
                num += twoExp * twoExp * 3;
                r -= twoExp;
                c -= twoExp;
            }
        }
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
