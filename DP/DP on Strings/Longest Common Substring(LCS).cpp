#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longCommSubstr(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int maxLen = 0;

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                // same

                int maxx = 0;
                if (s1[i - 1] == s2[j - 1])
                {
                    maxx = max(maxx, 1 + dp[i - 1][j - 1]);
                    maxLen = max(maxx, maxLen);
                }

                dp[i][j] = maxx;
            }
        }

        return maxLen;
    }
};