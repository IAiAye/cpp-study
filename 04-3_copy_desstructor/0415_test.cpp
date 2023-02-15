#include <iostream>

int main()
{
    char a[3] = "ab"; // 끝자리는 NULL이 들어간다.

    std::cout << a[2] << std::endl;
    if (! a[2])
    {
        std::cout << "!!" << std::endl;
    }
    
}