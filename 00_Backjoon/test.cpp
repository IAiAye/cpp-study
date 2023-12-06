#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int sum = 0;
    unordered_map<int, int> m;
    m[2] = 4;

    sum += m[0];

    return 0;
}