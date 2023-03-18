#include <iostream>
#include <vector>
using namespace std;

void combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        for (int i = 0; i < comb.size(); i++)
        {
            cout << comb[i] << ' ';
        }
        cout << '\n';
    }
    else if (depth == arr.size())
    {
        return;
    }
    else
    {
        // arr[depth]를 뽑은 경우
        comb[index] = arr[depth];
        combination(arr, comb, r - 1, index + 1, depth + 1);

        // arr[depth]를 뽑지 않은 경우
        combination(arr, comb, r, index, depth + 1);
    }
}

int main()
{
    int num, tmp;
    int r = 6;

    while (1)
    {
        vector <int> lotto;
        vector <int> comb(r);
        cin >> num;
        if (num == 0) return 0;

        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            lotto.push_back(tmp);
        }
        combination(lotto, comb, r, 0, 0);
        cout << endl;
    }
}
