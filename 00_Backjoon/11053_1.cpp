#include <iostream>
#include <vector>
using namespace std;

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
        
        if (arr.empty() || arr.back() < num)
        // 벡터의 마지막 수보다 클때만 추가.
        {
            arr.push_back(num);
        }
        else
        {
            auto it = lower_bound(arr.begin(), arr.end(), num);
            // 그 수보다 큰 첫번째 반복자 반환.
            *it = num;
            // 그 수를 num으로 치환해준다.
        }
    }
    
    cout << arr.size() << '\n';

    return 0;
}
