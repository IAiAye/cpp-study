#include <iostream>
#include <string>

int main()
{
    std::string s;
    while (1)
    {
        std::cin >> s; // 띄어쓰기 단위로 끊기때문에 문장을 받지 못한다.
        std::cout << "word : " << s << '\n';
    }
}