#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N - i; j++)
        {
            std::cout << ' ';
        }
        for (int j = 0; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }
    return 0;
}