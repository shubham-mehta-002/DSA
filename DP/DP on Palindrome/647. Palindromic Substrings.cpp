#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // base case for length = 1
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            cnt++;
        }

        for (int length = 2; length <= n; length++)
        {
            for (int i = 0; i + length - 1 < n; i++)
            {
                int j = i + length - 1;

                // length is 2
                if (i + 1 == j)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }

                // count
                if (dp[i][j])
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};