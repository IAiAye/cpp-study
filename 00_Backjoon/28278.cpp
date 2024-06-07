#include <iostream>
#include <vector>
using namespace std;

int countOfOrder;

void Input()
{
    cin >> countOfOrder;
}

void Solution()
{
    vector<int> myStack;
    int order = -1;
    int number = -1;

    while (countOfOrder--)
    {
        cin >> order;

        switch (order)
        {
        case 1:
            cin >> number;
            myStack.push_back(number);
            break;
        
        case 2:
            if (myStack.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << myStack.back() << '\n';
                myStack.pop_back();
            }
            break;

        case 3:
            cout << myStack.size() << '\n';
            


        default:
            break;
        }
    }
    
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