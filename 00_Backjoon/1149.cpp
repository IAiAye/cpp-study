#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int costs[3];
    int house[1001][3];
    for (int i = 0; i < 3; i++)
    {
        house[1000][i] = 0;
    }
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> costs[0] >> costs[1] >> costs[2];
        house[i][0] = min(house[i - 1][1],house[i - 1][2]) + costs[0]; // 이전 집까지를 다른 색으로 칠하는 최소값.
        house[i][1] = min(house[i - 1][0],house[i - 1][2]) + costs[1];
        house[i][2] = min(house[i - 1][0],house[i - 1][1]) + costs[2];
    }
    cout << min(house[n][0], min(house[n][1], house[n][2]));

    return 0;
}
