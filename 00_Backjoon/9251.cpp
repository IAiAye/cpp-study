#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a;
    string b;
    cin >> a >> b;

    int arr[1001][1001];
    int answer = 0;
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            arr[i][j] = 0; // 0으로 초기화.
        }
    }
    
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1; // 0,0 을 위해 1부터 시작. 같을 경우 
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
            if (arr[i][j] > answer)
            {
                answer = arr[i][j];
            }
        }
    }
    cout << answer;
    return 0;
}