#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
using ull = unsigned long long;

int n, m;
ull guitar[10];
ull canPlay;

int maxBit, result;
ull cache[10];

int countBit(ull bit)
{
    int res = 0;
    while (bit)
    {
        res += bit & 1;
        bit >>= 1;
    }
    return res;
}

void minGuitar(int idx, int cnt, ull bit)
{
    
    int Y = countBit(bit);

    if (maxBit < Y)
    {
        maxBit = Y;
        result = cnt;
    }
    else if (maxBit == Y)
        result = min(result, cnt);
    
    if (idx == n)
        return;
    
    // idx번째 기타 선택
    minGuitar(idx + 1, cnt + 1, bit | cache[idx]);
    // idx번째 기타 선택 X
    minGuitar(idx + 1, cnt, bit);
    
}

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string guitar, play;
        cin >> guitar >> play;
        for (int j = 0; j < m; j++)
        {
            if (play[j] == 'Y')
                cache[i] |= (1LL << (m - 1 - j));
        }
    }
}

void Solution()
{
    minGuitar(0, 0, 0);
    if (maxBit == 0)
        cout << -1 << '\n';
    else
        cout << result << '\n';
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