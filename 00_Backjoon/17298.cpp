#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
int ans[1000001];
stack <int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // 수열의 뒤에서부터 확인
    for (int i = n; i != 0; i--)
    {
        // 스택의 top이 수열보다 클때까지 -> 오른수가 나올때까지 그 사이 수 다 제거
        while(!s.empty() && s.top() <= arr[i]) s.pop();

        if (s.empty()) ans[i] = -1;
        // top이 오큰수이므로
        else ans[i] = s.top();

        s.push(arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    
    return 0;
}