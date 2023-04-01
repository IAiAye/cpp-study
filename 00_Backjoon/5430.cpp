#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        bool reverse = false;
        bool error = false;

        string p;
        cin >> p;

        int n;
        cin >> n;

        deque <int> dq;

        string arr;
        cin >> arr;
        string stmp = "";

        for (int j = 1; j < arr.length(); j++) // [1,2,3,4] 처리
        {
            if (isdigit(arr[j])) stmp += arr[j];
            else
            {
                if (!stmp.empty())
                {
                    dq.push_back(stoi(stmp));
                    stmp = "";
                }
            }
        }

        for (int k = 0; k < p.length(); k++) // 명렁어 수행
        {
            if (p[k] == 'R')
            {
                reverse = !reverse;
            }
            if (p[k] == 'D')
            {
                if (!dq.empty())
                {
                    if (!reverse) dq.pop_front(); // 정방향이면 앞에서
                    else dq.pop_back(); // 역방향이면 뒤에서
                }
                else
                {
                    error = true; // 비어있을때 D를 수행하면 에러 발생
                    break;
                }
            }
        }
        if (error)
        {
            cout << "error" << '\n';
        }
        else
        {
            if (dq.empty())
            {
                cout << "[]" << '\n';
            }
            else
            {
                if (!reverse)
                {
                    cout << '[' << dq[0];
                    for (int i = 1; i < dq.size(); i++)
                    {
                        cout << ',' << dq[i];
                    }
                }
                else
                {
                    cout << '[' << dq[dq.size() - 1];
                    for (int i = dq.size() - 2; i != -1; i--)
                    {
                        cout << ',' << dq[i];
                    }
                }
                cout << ']' << '\n';
            }
        }
    }
}