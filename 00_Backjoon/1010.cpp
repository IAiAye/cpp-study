#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    int n, m;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        int res = 1, tmp = 1;
        for (int i = m; i > m - n; i--) // 조합을 계산하는 다른 방법
        {
            res = res * i;
            res = res / tmp++;
        }
        cout << res << '\n';
    }
}