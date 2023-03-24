// 이진수로 읽기
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream in("text.txt", std::ios::binary); // 이진 데이터 그대로를 받겠다는 의미.
    std::string s;

    int x;
    if (in.is_open())
    {
        in.read((char*)(&x), 4);
        std::cout << std::hex << x << std::endl;
    }
    else
    {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }
    return 0;
}