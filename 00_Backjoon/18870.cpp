#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int num, tmp;
    cin >> num;
    vector <int> original_list;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        original_list.push_back(tmp);
    }
    vector <int> duplicated_list(original_list); // 복제
    sort(duplicated_list.begin(), duplicated_list.end()); // 복제 리스트를 정렬.
    duplicated_list.erase(unique(duplicated_list.begin(), duplicated_list.end()), duplicated_list.end()); // 정렬된 리스트에서 중복 제거.
    for (int i = 0; i < num; i++)
    {
        cout << lower_bound(duplicated_list.begin(), duplicated_list.end(), original_list[i]) - duplicated_list.begin() << ' ';
    } // 원래 리스트의 원소가 몇번째에 존재하는지 출력.
}