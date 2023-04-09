#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <long long> ans;
    int n;
    cin >> n;
    ans.push_back(1);
    ans.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        long long tmp;
        tmp = ans[i - 1] + ans[i - 2];
        ans.push_back(tmp % 15746);
    }
    cout << ans[n] % 15746;
}
