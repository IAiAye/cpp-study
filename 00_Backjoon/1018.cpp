#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string WB = "WBWBWBWB";
string BW = "BWBWBWBW";
vector <string> WB_board()
{
    vector <string> WB_board;
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            WB_board.push_back(WB);
        } else WB_board.push_back(BW);
    }
    return WB_board;
}
vector <string> BW_board()
{
    vector <string> BW_board;
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            BW_board.push_back(BW);
        } else BW_board.push_back(WB);
    }
    return BW_board;
}

int main()
{
    int n, m;
    int min_cnt = 64;
    cin >> n >> m;
    vector <string> board;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        board.push_back(str);
    }
    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {
            int BW_cnt = 0;
            int WB_cnt = 0;
            for (int p = 0; p < 8; p++)
            {
                for (int q = 0; q < 8; q++)
                {
                    if (board[i + p][j + q] != BW_board()[p][q])
                    {
                        BW_cnt++;
                    }
                    if (board[i + p][j + q] != WB_board()[p][q])
                    {
                        WB_cnt++;
                    }
                }
            }
            if (BW_cnt < min_cnt)
            {
                min_cnt = BW_cnt;
            }
            if (WB_cnt < min_cnt)
            {
                min_cnt = WB_cnt;
            }
        }
    }
    cout << min_cnt;
}
