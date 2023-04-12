#include <iostream>
using namespace std;

int psum[1025][1025]; // 1,1에서 x, y 까지의 넓이의 누적합

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
            psum[i][j] = psum[i][j - 1] + psum[i - 1][j] + tmp - psum[i - 1][j - 1];
        }
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++)
    {
        long long ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        ans = psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
    
    return 0;
}
