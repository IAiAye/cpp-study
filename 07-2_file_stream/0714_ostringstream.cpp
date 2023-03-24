#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string to_str(int x)
{
    ostringstream ss;
    ss << x; // 숫자를 문자열로 변환하면서 받는다.
    return ss.str();
}
int main()
{
    cout << "문자열로 변환 :: 1 + 2 = " << to_str(1 + 2) << endl;
    return 0;
}