#include <iostream>

int left = 0;
int right = 500;
int target = 237;
int cnt = 0;

bool isBelow(int x)
{
    bool result = false;

    if (target < x)
    {
        result = true;
    }
    return result;
}

int binarySearch(int left, int right)
{
    std:: cout << left << ' ' << right << '\n';
    if (left == right) return left;
    
    cnt++;
    int mid = (left + right) / 2;
    
    // left ~ mid에 타겟이 존재할때
    if (isBelow(mid + 1))
    {
        return binarySearch(left, mid);
    }
    else
    {
        return binarySearch(mid + 1, right);
    }
}

int main()
{
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isBelow(mid + 1)) right = mid;
        else left = mid + 1;
    }

    std::cout << cnt;
}