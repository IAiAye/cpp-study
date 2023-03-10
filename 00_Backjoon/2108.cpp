#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr;
    int num, temp = 0;
    int mean, middle, most_val, range = 0;
    int most = -1;
    int number[8001] = {0,}; // 숫자의 개수를 세주는 인덱스
    bool not_first = false;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        arr.push_back(temp);
        mean += temp;
        number[temp + 4000]++; //숫자가 나올때마다 하나씩 추가.
    }
    sort(arr.begin(), arr.end());

    mean = round((float)mean / num);
    middle = arr[(num - 1) / 2];

    for (int i = 0; i < 8001; i++)
    {
        if (number[i] != 0)
        {
            if (number[i] == most && not_first)
            {
                most_val = i - 4000;
                not_first = false;
            }
            if (number[i] > most)
            {
                most = number[i];
                most_val = i - 4000;
                not_first = true;
            }
        }
    }
    range = arr.back() - arr.front();

    cout << mean << '\n';
    cout << middle << '\n';
    cout << most_val << '\n';
    cout << range;
}