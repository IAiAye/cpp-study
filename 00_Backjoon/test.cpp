#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3};
    
    // index 1에 4 추가
    vec[1] = 4;
    // vec: {1, 4, 3}
    
    // index 1에 5 추가
    vec.push_back(5);
    // vec: {1, 4, 3, 5}
    
    // index 1에 6 추가
    vec.push_back(6);
    // vec: {1, 4, 3, 5, 6}
    
    // index 1에 7 추가
    vec.push_back(7);
    // vec: {1, 4, 3, 5, 6, 7}
    
    // index 1에 8 추가
    vec.push_back(8);
    // vec: {1, 4, 3, 5, 6, 7, 8}
    
    cout << vec[1] << endl;
    // 출력: 8
    
    return 0;
}