#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int num;
    int sum = 0;
    cin >> n;
    vector <int> stack;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num != 0)
        {
            stack.push_back(num);
            sum += num;
        }
        else
        {
            sum -= stack.back();
            stack.pop_back();
        }
    }
    cout << sum;
}
