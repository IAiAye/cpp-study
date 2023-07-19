#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int t, num;

double roundHalfUp(double num, int decimalPlaces) 
{
    double multiplier = pow(10.0, decimalPlaces);
    return (num >= 0.0) ? floor(num * multiplier + 0.5) / multiplier : ceil(num * multiplier - 0.5) / multiplier;
}

void Input()
{
    cin >> t;
}

void Solution()
{    
    while (t--)
    {
        cin >> num;
        int* score = new int[num];
        double avg = 0;
        for (int i = 0; i < num; i++)
        {
            cin >> score[i];
            avg += score[i];
        }
        avg = avg / num;

        double cnt = 0;
        for (int i = 0; i < num; i++)
        {
            if (score[i] > avg) cnt++;
        }
        cnt = cnt / num * 100;
        cnt = roundHalfUp(cnt, 3);
        cout << fixed << std::setprecision(3);
        cout << cnt << "% \n";

        delete[] score;
    }
    
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
    
    return 0;
}