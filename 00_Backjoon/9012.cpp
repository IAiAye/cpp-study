#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    string parenthesis;
    for (int i = 0; i < n; i++)
    {
        cin >> parenthesis;
        bool flag = true; // 스택이 지하로 들어가는 것을 방지
        cnt = 0;
        for (int j = 0; j < parenthesis.length(); j++)
        {
            if (parenthesis[j] == '(') cnt++;
            else cnt--;
            if (cnt < 0)
            {
                flag = false;
                break;
            }
        }
        if (cnt == 0 && flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
