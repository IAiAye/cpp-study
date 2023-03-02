#include <iostream>
using namespace std;
int main()
{
    int test_case; //T
    int floor; //k
    int num; //n
    int arr[14];
    cin >> test_case;
    
    for (int i = 0; i < test_case; i++)
    {
        for (int i = 0; i < 14; i++)
        {
            arr[i] = i + 1;
        }
        cin >> floor;
        cin >> num;
        for (int j = 0; j < floor; j++)
        {
            int sum = 0;
            for (int k = 0; k < num; k++)
            {
                sum += arr[k];
                arr[k] = sum;
            }
        }
        cout << arr[num - 1] << "\n";
    }
    
}