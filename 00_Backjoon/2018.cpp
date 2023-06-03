#include <iostream>
using namespace std;

int startPoint = 1;
int endPoint = 1;
int N;
int cnt = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL); 

    std::cin >> N;
    while (startPoint != N)
    {
        int sum = 0;
        for (int i = startPoint; i <= endPoint; i++)
        {
            sum += i;
        }
        if (sum == N)
        {
            cnt++;
            endPoint++;
        }
        else if (sum > N) startPoint++;
        else endPoint++;
    }
    std::cout << cnt;
}