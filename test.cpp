#include <iostream>

/*
void dfs(secretbox box, int left, int right)
{
    if (left > right) return;
    int numTarget = box.checkTargets(left, right);
    if (right - left + 1 == numTarget)
    {
        for (int i = left; i <= right; i++)
        {
            push(i);
        }
    }
    int mid = (left + right) / 2;

    int leftNumTarget = box.checkTargets(left, mid);
    int rightNumTarget = numTarget - leftNumTarget;
    if (leftNumTarget > 0) dfs(box, left, mid);
    if (rightNumTarget > 0) dfs(box, mid + 1, right);
}
*/