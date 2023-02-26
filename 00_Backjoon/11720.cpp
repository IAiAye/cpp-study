#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    int sum = 0;
    cin >> N;

    string s;
    cin >> s;
    for (int i = 0; i < N; i++)
    {
        sum += s[i] - '0';
    }
    cout << sum << endl;

    return 0;
}