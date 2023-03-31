#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void push(vector<int> &a)
{
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
}
void pop(vector<int> &a)
{
    if (!a.empty())
    {
        cout << a.back() << '\n';
        a.pop_back();
    } else cout << -1 << '\n';
}
void size(vector<int> &a) { cout << a.size() << '\n'; }
void empty(vector<int> &a) { cout << a.empty() << '\n'; }
void top(vector<int> &a)
{
    if (!a.empty()) cout << a.back() << '\n';
    else cout << -1 << '\n';
}

int main()
{
    int n;
    string s;
    cin >> n;
    vector <int> stack;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "push") push(stack);
        else if (s == "pop") pop(stack);
        else if (s == "size") size(stack);
        else if (s == "empty") empty(stack);
        else if (s == "top") top(stack);
    }
}
