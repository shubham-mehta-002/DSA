#include <bits/stdc++.h>
using namespace std;
class Solution

{
    int n, m;
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};

public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        n = coins.size();
        m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        // base case
        if (coins[n - 1][m - 1] < 0)
        {
            dp[n - 1][m - 1][1] = 0;
            dp[n - 1][m - 1][2] = 0;
            dp[n - 1][m - 1][0] = coins[n - 1][m - 1];
        }
        else
        {
            for (int times = 0; times <= 2; times++)
            {
                dp[n - 1][m - 1][times] = coins[n - 1][m - 1];
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                    continue;

                for (int times = 0; times <= 2; times++)
                {
                    int maxx = INT_MIN;

                    for (int k = 0; k < 2; k++)
                    {
                        int new_r = i + dx[k];
                        int new_c = j + dy[k];
                        if (new_r >= 0 && new_c >= 0 && new_r < n && new_c < m)
                        {
                            // take
                            if (dp[new_r][new_c][times] != INT_MIN)
                            {
                                maxx = max(maxx, coins[i][j] + dp[new_r][new_c][times]);
                            }

                            // skip
                            if (coins[i][j] < 0 && times > 0 && dp[new_r][new_c][times - 1] != INT_MIN)
                            {
                                maxx = max(maxx, dp[new_r][new_c][times - 1]);
                            }
                        }
                    }
                    dp[i][j][times] = maxx;
                }
            }
        }
        return dp[0][0][2];
    }
};