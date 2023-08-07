#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t = 6;
    int n = t;
    vector<int> factor;

    for (int i = 2; i * i <= t; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            factor.push_back(i);
        }
    }
    if (n != 1)
        factor.push_back(n);
    for (int i : factor)
        cout << i << ' ';
    
}