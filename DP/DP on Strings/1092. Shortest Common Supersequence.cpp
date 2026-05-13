#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        string res = "";
        int n = str1.size();
        int m = str2.size();

        // find LCS
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // iterate backwards
        int i = n;
        int j = m;

        while (i > 0 || j > 0)
        {
            if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1])
            {
                res += str1[i - 1];
                i--;
                j--;
            }
            else if (i > 0 && dp[i][j] == dp[i - 1][j])
            {
                res += str1[i - 1];
                i--;
            }
            else if (j > 0)
            {
                res += str2[j - 1];
                j--;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};