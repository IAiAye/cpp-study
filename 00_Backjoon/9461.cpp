#include <iostream>
#include <vector>
using namespace std;
int t;
void tri()
{
    int n;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        long long tmp;
        vector <long long> answer = {1, 1, 1, 2, 2};
        for (int j = 5; j <= n; j++)
        {
            tmp = answer[j - 1] + answer[j - 5];
            answer.push_back(tmp);
        }
        cout << answer[n - 1] << '\n';
    }
}

int main()
{
    cin >> t;
    tri();
}
