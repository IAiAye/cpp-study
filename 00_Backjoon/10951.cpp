#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int a, b;

    while (cin >> a >> b) // eof (ctrl + D)가 들어오면 false가 되면서 종료.
    {
        cout << a + b << "\n";
    }
    return 0;
}