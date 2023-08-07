#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#define endl '\n'
#define ll long long
#define all(x) x.begin(),x.end()
using namespace std;

vector<int>v[500'005]; //트리
int n; // 노드의 개수
ll rgb[500'005][3]; // rgb[index][rgb 값]:= 문제에서 주어지는 rgb값
ll dp[500'005][3]; //dp[index][rgb 값] := index를 루트노드로 하는 트리가 'rgb값'을 가질때의 최댓값
vector<char>str; // RGB문자열
string tmp = "RGB";


ll solve(int x,int pre,int k) {
    // 값이 있다면, dp처리
    if (dp[x][k])return dp[x][k];

    for (int nxt : v[x]) {
        if (nxt != pre) {
            ll a = solve(nxt, x, (k + 1) % 3);
            ll b = solve(nxt, x, (k + 2) % 3);

            // dp[x][k]의 최댓값 갱신, 정답으로 사용될 RGB문자열 값 갱신
            if (a > b)dp[x][k] += a, str[nxt] = tmp[(k + 1) % 3];
            else dp[x][k] += b, str[nxt] = tmp[(k + 2) % 3];
        }
    }

    // 현재 노드의 RGB값 더해서 return
    return dp[x][k]+=rgb[x][k];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    str.resize(n + 1);
    // 그래프 만들기
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    //rgb 값 입력 받기
    for (int i = 1; i <= n; i++) {
        ll r, g, b; cin >> r >> g >> b;
        rgb[i][0] = r, rgb[i][1] = g, rgb[i][2] = b;
    }

    //답 구하기
    ll mx = -1; // 최댓값
    vector<char>ans; //RGB문자열 정답
    for (int i = 0; i < 3; i++) {
        
        if (mx < solve(1, -1, i)) {
            //새로운 값이 최댓값일 경우, 답 갱신
            str[1] = tmp[i];
            mx = dp[1][i];
            ans = str;
        }
    }

    //답 출력
    cout << mx << endl;
    for (int i = 1; i <= n; i++)cout << ans[i];
    cout << endl;
}