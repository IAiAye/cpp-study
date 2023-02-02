// switch

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int user_input;
    cout << "저의 정보를 표시해줍니다" << endl;
    cout << "1. Name" << endl;
    cout << "2. Age" << endl;
    cout << "3. Gender" << endl;
    cin >> user_input;

    switch (user_input)
    {
    case 1:
        cout << "Mad Monster!" << endl;
        break;
    
    case 2:
        cout << "15" << endl;
        break;

    case 3:
        cout << "Male" << endl;
        break;
        
    default:
        cout << "Nothing?" << endl;
        break;
    }
    return 0;
}
