#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int cnt = num;

    int test_num;
    for (int i = 0; i < num; i++)
    {
        cin >> test_num;
        
        if (test_num > 2)
        {
            for (int i = 2; i < test_num; i++)
            {
                if (test_num % i == 0)
                {
                    cnt--;
                    break;
                }
            }
        }
        else if (test_num == 1)
        {
            cnt--;
        }
    }
    cout << cnt;
}