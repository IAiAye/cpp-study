#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <int> numbers;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        std::cin >> temp;
        numbers.push_back(temp);
    }
    
    sort(numbers.begin(), numbers.end());
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        int checkNum = numbers[i];

        int startPoint = 0;
        int endPoint = N - 1;

        // 투 포인트가 확인하는 수와 겹치면 안된다.
        if (startPoint == i) startPoint++;
        if (endPoint == i) endPoint--;

        while (startPoint != endPoint)
        {
            int sum = numbers[startPoint] + numbers[endPoint];
            if (checkNum == sum)
            {
                ans++;
                break;
            }
            else if (checkNum < sum) endPoint--;
            else startPoint++;

            // 투 포인트가 확인하는 수와 겹치면 안된다.
            if (startPoint == i) startPoint++;
            if (endPoint == i) endPoint--;
        }
    }
    
    std::cout << ans;

    return 0;
}