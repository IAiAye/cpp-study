#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string a, b;
// a의 i번째까지, b의 j번째까지 lcs의 길이 : length[i][j]
int length[1001][1001];

string traceBack(int i, int j)
{
    if (i == 0 || j == 0) return "";
    // length에서 대각선으로 1이 증가한 것과 같다.
    if (a[i - 1] == b[j - 1]) return traceBack(i - 1, j - 1) + a[i - 1];

    if (length[i][j - 1] >= length[i - 1][j]) return traceBack(i, j - 1);
    return traceBack(i - 1, j);
}

void Input()
{
    std::cin >> a >> b;
}

void Solution()
{
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            // a의 i번째와 b의 j번째가 같다면, i - 1, j - 1번째 까지의 LCS의 길이에 1을 더해준다.
            if (a[i] == b[j]) length[i + 1][j + 1] = length[i][j] + 1;
            // 같지않다면, 글자를 한 개씩 뺀 것들 중 LCS의 길이가 큰 것이 다음의 길이가 된다.
            else length[i + 1][j + 1] = max(length[i + 1][j], length[i][j + 1]);
        }
    }
    std::cout << length[a.length()][b.length()] << '\n';
    std::cout << traceBack(a.length(), b.length()) << '\n';
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