#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    while (1)
    {
        vector <int> tri(3);
        cin >> tri[0] >> tri[1] >> tri[2];
        if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0)
        {
            return 0;
        }
        
        sort(tri.begin(), tri.end());

        if (tri[0] + tri[1] <= tri[2])
        {
            cout << "Invalid";
        }
        else if (tri[0] == tri[1] && tri[1] == tri[2])
        {
            cout << "Equilateral";
        }
        else if (tri[0] == tri[1] || tri[1] == tri[2] || tri[2] == tri[0])
        {
            cout << "Isosceles";
        }
        else cout << "Scalene";
        cout << '\n';
    }
}