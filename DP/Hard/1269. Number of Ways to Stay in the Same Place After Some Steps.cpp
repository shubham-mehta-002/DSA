#include <bits/stdc++.h>
using namespace std;
class Solution
{
    const int MOD = 1e9 + 7;

public:
    // int find(int index, int steps, int arrLen,vector<vector<int>>&dp){
    //     if(steps == 0){
    //         if(index == 0) return 1;
    //         return 0;
    //     }

    //     if(dp[index][steps] != -1){
    //         return dp[index][steps];
    //     }
    //     long long ways = 0;
    //     // left
    //     if(index > 0){
    //         ways += find(index-1,steps-1,arrLen,dp);
    //     }

    //     // right
    //     if(index < arrLen-1){
    //         ways += find(index+1,steps-1,arrLen,dp);
    //     }

    //     // stay
    //     ways += find(index, steps-1,arrLen,dp);

    //     return dp[index][steps] = ways % MOD;
    // }
    int numWays(int steps, int arrLen)
    {
        arrLen = min(arrLen, steps / 2 + 1);

        vector<vector<int>> dp(arrLen + 1, vector<int>(steps + 1, 0)); // index | steps

        // base case
        dp[0][0] = 1;

        for (int remSteps = 1; remSteps <= steps; remSteps++)
        {
            for (int index = 0; index < arrLen; index++)
            {
                long long ways = 0;

                // left
                if (index > 0)
                {
                    ways += dp[index - 1][remSteps - 1];
                }
                // right
                if (index < arrLen - 1)
                {
                    ways += dp[index + 1][remSteps - 1];
                }

                // stay
                ways += dp[index][remSteps - 1];

                dp[index][remSteps] = ways % MOD;
            }
        }
        return dp[0][steps];
    }
};