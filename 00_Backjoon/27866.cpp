#include <iostream>
#include <string>
int main()
{
    std::string str;
    int num;
    std::cin >> str;
    std::cin >> num;
    std::cout << str[num - 1];
    return 0;
}