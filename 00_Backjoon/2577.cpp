#include <iostream>
#include <string>
using namespace std;
int main()
{
    int A,B,C;
    int digit[10] = {0};
    cin >> A >> B >> C;
    string str = to_string(A * B * C);
    for (int i = 0; i < str.length(); i++)
    {
        digit[ str[i] - '0' ]++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << digit[i] << '\n';
    }
}