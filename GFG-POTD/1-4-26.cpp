#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int end, int n, vector<vector<int>> &dp)
    {
        if (n == 0)
            return 1;

        if (dp[n][end] != -1)
        {
            return dp[n][end];
        }

        if (end == 1)
        {
            return dp[n][end] = find(0, n - 1, dp);
        }
        else
        {
            return dp[n][end] = find(0, n - 1, dp) + find(1, n - 1, dp);
        }
    }
    int countStrings(int n)
    {
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return find(0, n - 1, dp) + find(1, n - 1, dp);
    }
};