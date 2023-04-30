#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

// 사람의 키와 스택에 존재하는 같은 키의 사람 수
stack <pair <int,int>> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    long long cnt = 0;
    int now;

    for (int i = 1; i <= n; i++)
    {
        cin >> now;
        int cnt_same = 1;
        // 작아지는 방향으로 스택 쌓기, 더 크거나 같은 키가 나오면 반복문 돌입
        while (!s.empty() && s.top().first < now)
        {
            cnt += s.top().second;
            //cout << s.top().first << ' ' << s.top().second << ' ' << cnt << " 클" << '\n';
            // 사이에 있는 사람 제거
            s.pop();
        }

        if (!s.empty())
        {
            if (s.top().first == now)
            {
                // (똑같은 숫자가 있는 만큼 -1) 추가를 해준다.
                cnt += s.top().second;
                //cout << s.top().first << ' ' << s.top().second << ' ' << cnt << " 똑1" << '\n';
                cnt_same = s.top().second + 1;

                // 동일한 숫자 전에 다른 큰 숫자가 하나 있다면, 그것과도 마주볼 수 있다.
                // 똑같은 숫자는 하나로 압축되었다고 생각한다.
                if (s.size() > 1) 
                {
                    cnt++;
                    //cout << s.top().first << ' ' << s.top().second << ' ' << cnt << " 똑2" << '\n';
                }
                s.pop();
            }
            // 앞뒤로 있을때 세주기
            else 
            {
                cnt++; 
                //cout << s.top().first << ' ' << s.top().second << ' ' << cnt << " 작" << '\n';
            }
        }

        s.push({now, cnt_same});
    }
    cout << cnt;

    return 0;
}

/*
A C B가 있을때,
A와 B가 쌍이 되려면, (A >= C) && (B >= C) 이어야 한다.
*/