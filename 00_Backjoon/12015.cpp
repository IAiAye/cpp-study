#include <iostream>
#include <vector>
using namespace std;

void biggerThanNum(vector<int> &a, int num)
{
    int left = 0;
    int right = a.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] >= num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    a[left] = num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        
        // 벡터의 마지막 수보다 클때만 추가.
        if (arr.empty() || arr.back() < num)
        {
            arr.push_back(num);
        }
        else
        {
            // 그 수보다 큰 첫번째 반복자 반환.
            // 그 수를 num으로 치환해준다.
            biggerThanNum(arr, num);
        }
    }
    
    cout << arr.size() << '\n';

    return 0;
}
