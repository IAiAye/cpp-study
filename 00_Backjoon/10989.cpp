#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // 시간 초과 해결

    int num, temp;
    cin >> num;
    int index[10001] = {0};
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        index[temp]++;
    }
    for (int j = 0; j < 10001; j++)
    {
        if (index[j] != 0)
        {
            for (int k = 0; k < index[j]; k++)
            {
                cout << j << '\n';
            }
        }
    }
}