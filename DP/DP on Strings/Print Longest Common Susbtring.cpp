#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonSubstring(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int maxLen = 0;
        int endIndex = 0; // ending index in s1

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    if (dp[i][j] > maxLen)
                    {
                        maxLen = dp[i][j];
                        endIndex = i - 1;
                    }
                }
            }
        }

        // Extract the substring from s1
        if (maxLen == 0)
            return "";
        return s1.substr(endIndex - maxLen + 1, maxLen);
    }
};