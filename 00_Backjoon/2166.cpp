#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 10001
int n;
vector<pair <ll, ll>> board;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> board[i].first >> board[i].second;
        if (i != 0)
        {
            board[i].first -= board[0].first;
            board[i].second -= board[0].second;
        }
    }
    double area = 0;
    for (int i = 1; i + 1 <= n - 1; i++)
    {
        ll x1 = board[i].first;
        ll y1 = board[i].second;

        ll x2 = board[i + 1].first;
        ll y2 = board[i + 1].second;

        area += x1 * y2 - x2 * y1;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(area / 2) << '\n';
    
    return 0;
}
