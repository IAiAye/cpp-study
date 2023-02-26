#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;

    string s;
    for (int i = 0; i < T; i++)
    {
        cin >> s;
        cout << s.front() << s.back() << "\n";
    }
    
    return 0;
}