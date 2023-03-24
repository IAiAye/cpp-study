//파일에서의 입출력
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // 파일 읽기 준비
    std::ifstream in("text.txt"); // 소멸자에서 자동으로 close해준다.
    std::string s;

    if (in.is_open())
    {
        in >> s; // 공백문자가 나올때까지만 읽는다. cin 과 동일.
        std::cout << "입력 받은 문자열 : " << s << std::endl;
    }
    else
    {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }
    in.close(); // 새로운 파일을 같은 객체에 받기위해선 close를 따로 해주어야 한다.
    in.open("other.txt");
    if (in.is_open())
    {
        in >> s; // 공백문자가 나올때까지만 읽는다. cin 과 동일.
        std::cout << "입력 받은 문자열 : " << s << std::endl;
    }
    else
    {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }

    return 0;
}