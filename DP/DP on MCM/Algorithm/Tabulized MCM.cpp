#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // base case
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 0;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                int mini = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, steps);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};