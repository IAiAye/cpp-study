#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    while(1)
    {
        string str;
        getline(std::cin, str, '.');
        if (str == "") break;

        bool flag = true;
        stack <char> stack;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '(') stack.push('(');
            else if (str[j] == ')')
            {
                if (!stack.empty() && stack.top() == '(')
                {
                    stack.pop();
                }
                else { flag = false; break; }
            }
            if (str[j] == '[') stack.push('[');
            else if (str[j] == ']')
            {
                if (!stack.empty() && stack.top() == '[')
                {
                    stack.pop();
                }
                else { flag = false; break; } 
            }
        }
        if (stack.empty() && flag) cout << "yes" << '\n';
        else cout << "no" << '\n';
        std::cin.ignore(); // 개행문자가 들어가는 것을 방지.
    }
}
