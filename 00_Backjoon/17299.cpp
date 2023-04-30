#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
// 숫자 배열
int seq[1000001];
// 숫자의 개수
int num[1000001];
int ans[1000001];
// 숫자의 개수와 그 숫자를 저장
vector <pair <int,int>> arr;
stack <pair <int,int>> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
        num[seq[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        // 숫자의 개수와 그 숫자를 입력해준다.
        arr.push_back({num[seq[i]],seq[i]});
    }
    
    // 수열의 뒤에서부터 확인
    for (int i = n; i > 0; i--)
    {
        // 스택의 top이 수열보다 클때까지 -> 오른수가 나올때까지 그 사이 수 다 제거
        while(!s.empty() && s.top().first <= arr[i - 1].first) s.pop();

        if (s.empty()) ans[i] = -1;
        // top이 오큰수이므로
        else ans[i] = s.top().second;

        s.push(arr[i - 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    
    return 0;
}