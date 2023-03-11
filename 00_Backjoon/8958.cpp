#include <iostream>
#include <string>
using namespace std;
int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        string OX;
        int score = 0;
        int cnt = 0;
        cin >> OX;
        for (int j = 0; j < OX.length(); j++)
        {
            if (OX[j] == 'O')
            {
                cnt++;
                score += cnt;
            } else cnt = 0;
        }
        cout << score << '\n';
    }
}