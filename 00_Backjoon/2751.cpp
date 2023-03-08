#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num, temp;
    vector <int> a; // 벡터 구조 선언
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end()); // 순서를 정렬해주는 sort 함수.
    for (int i = 0; i < num; i++)
    {
        cout << a[i] << '\n';
    }
}