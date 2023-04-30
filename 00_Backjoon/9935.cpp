#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    string bomb;

    cin >> str >> bomb;
    string ans;
    
    int bombIdx = bomb.length() - 1;

    for (int i = 0; i < str.length(); i++)
    {
        ans += str[i];
        // 문자열을 하나씩 확인하다가 폭탄의 마지막 문자가 들어왔을때 앞으로 넘어가며 확인
        if (str[i] == bomb.back())
        {
            bool flag = true;
            int ansIdx = ans.length() - 1;
            // 폭탄의 길이만큼 확인하기
            for (int j = 1; j < bomb.length(); j++)
            {
                // 현재 있는 ans의 길이가 폭탄의 길이보다 긴지 확인
                if (ansIdx >= j)
                {
                    // 뒤에서부터 확인해가며 다르다면 깃발을 내리고 탈출
                    if (ans[ansIdx - j] != bomb[bombIdx - j])
                    {
                        flag = false;
                        break;
                    }
                }
                // 길이가 짧아도 안되므로 탈출
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int j = 0; j <= bombIdx; j++)
                {
                    ans.pop_back();
                }
            }
        }
    }
    if (ans == "")
    {
        cout << "FRULA";
    }
    else
    {
        cout << ans;
    }

    return 0;
}