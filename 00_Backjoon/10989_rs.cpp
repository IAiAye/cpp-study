#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 10000000

queue <int> numbers[10];
int n;
int arr[MAX];

void Solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int digit = 1;
    while (digit <= MAX)
    {
        for (int i = 0; i < n; i++)
        {
            int number = (arr[i] / digit) % 10;
            numbers[number].push(arr[i]);
        }
        int idx = 0;
        for (int i = 0; i < 10; i++)
        {
            while (!numbers[i].empty())
            {
                arr[idx++] = numbers[i].front();
                numbers[i].pop();
            }
        }
        digit *= 10;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}