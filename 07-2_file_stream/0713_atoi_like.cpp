// atoi 대신 사용할수 있는 함수
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
double to_number(string s)
{
    istringstream ss(s);
    double x;
    ss >> x;
    return x;
}
int main()
{
    cout << "변환 :: 1 + 2 = " << to_number("1") + to_number("2") << endl;
    return 0;
}