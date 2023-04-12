#include <iostream>
using namespace std;

int psum[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> tmp;
            psum[i][j] = psum[i][j - 1] + tmp; // 각 행마다 누적합 계산.
        }
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++)
    {
        long long ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++)
        {
            ans += psum[i][y2] - psum[i][y1 - 1];
        }
        cout << ans << '\n';
    }
    
    return 0;
}
