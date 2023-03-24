#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream out("test.txt", std::ios::app); // 파일이 없을 경우 생성

    std::string s;
    if (out.is_open())
    {
        out << "덧붙이기~"; // 파일에 내용이 존재하더라도 초기화 후 작성, 객체 생성시 app 옵션을 준다면 뒤에 추가한다.
    }
    return 0;
}
