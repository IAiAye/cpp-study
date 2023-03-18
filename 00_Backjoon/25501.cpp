#include <iostream>
#include <string.h>
using namespace std;
int cnt = 0;
int recursion(const char* s, int l, int r)
{
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char* s)
{
    cnt = 0;
    return recursion(s, 0, strlen(s)-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        char tmp[1001]; //string을 쓰면 시간이 오래걸린다.
        cin >> tmp;
        cout << isPalindrome(tmp) << ' ' << cnt << '\n';
    }
}