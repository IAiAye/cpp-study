#include <iostream>
#include <string>
using namespace std;
int main()
{
    int test_case;
    double num_student;

    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        int score[1000] = {0};
        int sum = 0;
        int avg = 0;
        double over_avg = 0;
        cin >> num_student;
        for (int j = 0; j < num_student; j++)
        {
            cin >> score[j];
            sum += score[j];
        }
        avg = sum / num_student;
        for (int j = 0; j < num_student; j++)
        {
            if (score[j] > avg)
            {
                over_avg += 1;
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << over_avg / num_student * 100 << "% \n";
    }
    
    return 0;
}