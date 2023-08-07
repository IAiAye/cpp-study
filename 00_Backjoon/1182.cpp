#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int n, s;
int arr[20];
int cnt;

void Comb(vector<int> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        int sum = 0;
        for (int i = 0; i < comb.size(); i++)
            sum += comb[i];
        if (sum == s)
            cnt++;
    }
    else if (depth == n)
        return;
    else
    {
        comb[index] = arr[depth];
        Comb(comb, r - 1, index + 1, depth + 1);

        Comb(comb, r, index, depth + 1);
    }
}


void Input()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void Solution()
{
    for (int i = 1; i <= n; i++)
    {
        vector<int> comb(i);
        Comb(comb, i, 0, 0);
    }
    cout << cnt << '\n';
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