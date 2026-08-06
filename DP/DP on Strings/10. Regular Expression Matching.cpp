#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case
        dp[n][m] = true;

        // base case II:
        int index = m - 2;
        while (index >= 0 && p[index + 1] == '*')
        {
            dp[n][index] = true;
            index -= 2;
        }

        for (int index1 = n - 1; index1 >= 0; index1--)
        {
            for (int index2 = m - 1; index2 >= 0; index2--)
            {
                bool ans = false;
                if (index2 + 1 < m && p[index2 + 1] == '*')
                {
                    // skip this pattern
                    ans |= dp[index1][index2 + 2];

                    // compare
                    if (p[index2] == '.' || s[index1] == p[index2])
                    {
                        ans |= dp[index1 + 1][index2];
                    }
                }
                else if (p[index2] == '.' || s[index1] == p[index2])
                {
                    ans |= dp[index1 + 1][index2 + 1];
                }

                dp[index1][index2] = ans;
            }
        }

        return dp[0][0];
    }
};