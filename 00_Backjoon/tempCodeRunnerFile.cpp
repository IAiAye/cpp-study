    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= costs_sum; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }