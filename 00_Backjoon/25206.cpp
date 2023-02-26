#include <iostream>
#include <string>
using namespace std;
int main()
{
    string subject;
    double point = 0;
    double sum = 0;

    for (int i = 0; i < 20; i++)
    {
        double point_sub = 0;
        getline(cin, subject);
        for (int j = 0; j < subject.length(); j++)
        {
            if (subject[j] == ' ')
            {
                if (subject[j + 5] == 'P') // P 패스
                {
                    break;
                }
                point_sub = subject[j + 1] - '0'; // 숫자로 변환.
                point += point_sub;

                if (subject[j + 5] == 'F')
                {
                    break;
                }
                if (subject[j + 5] == 'D')
                {
                    if (subject[j + 6] == '+')
                    {
                        sum += point_sub * 1.5;       
                        break;
                    }
                    else
                    {
                        sum += point_sub * 1.0;
                        break;
                    }
                }
                if (subject[j + 5] == 'C')
                {
                    if (subject[j + 6] == '+')
                    {
                        sum += point_sub * 2.5;       
                        break;
                    }
                    else
                    {
                        sum += point_sub * 2.0;
                        break;
                    }
                }
                if (subject[j + 5] == 'B')
                {
                    if (subject[j + 6] == '+')
                    {
                        sum += point_sub * 3.5;       
                        break;
                    }
                    else
                    {
                        sum += point_sub * 3.0;
                        break;
                    }
                }
                if (subject[j + 5] == 'A')
                {
                    if (subject[j + 6] == '+')
                    {
                        sum += point_sub * 4.5;       
                        break;
                    }
                    else
                    {
                        sum += point_sub * 4.0;
                        break;
                    }
                }
            }
        }
    }
    cout << fixed;
    cout.precision(6);
    cout << sum / point << endl;
    return 0;
}