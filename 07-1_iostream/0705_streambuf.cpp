#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;

    char peek = cin.rdbuf()->snextc(); 
    // rdbuf는 스트림버프 객체를 가리키는 포인터를 리턴한다.
    // snextc함수는 스트림 위치 지정자를 한칸 전진시키고 그자리에 해당하는 문자를 엿본다.
    // 따라서 hello를 읽고 나서 공백에 스트림 위치 지정자가 위치해있는데 w로 위치지정자를 옮기고 엿보게 된다.
    if (cin.fail()) cout << "Failed";
    cout << "두 번째 단어 맨 앞글자 : " << peek << endl;
    cin >> s;
    cout << "다시 읽으면 : " << s << endl;
}

/*
streambuf 클래스에는 입력 버퍼 get area, 출력 버퍼 put area가 있다.
*/