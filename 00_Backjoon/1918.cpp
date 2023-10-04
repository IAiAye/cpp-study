#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <stack>
using namespace std;

string str;

void Input()
{
    cin >> str;
}

void Solution()
{
    // */ 이 나오면 즉시 처리
    stack<char> op;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            op.push(str[i]);    
        }
        // 우선 순위 먼저
        else if (str[i] == '*' || str[i] == '/')
        {
            while (!op.empty() && (op.top() == '*' || op.top() == '/'))
            {
                cout << op.top();
                op.pop();
            }
            op.push(str[i]);
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            while (!op.empty() && op.top() != '(')
            {
                cout << op.top();
                op.pop();
            }
            op.push(str[i]);
            
        }
        else if (str[i] == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                cout << op.top();
                op.pop();
            }
            op.pop();

        }
        else
        {
            cout << str[i];
        }
    }
    while (!op.empty())
    {
        cout << op.top();
        op.pop();
    }
    cout << '\n';
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}