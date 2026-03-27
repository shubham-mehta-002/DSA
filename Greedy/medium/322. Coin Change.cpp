#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int find(int index, vector<int>&coins, int target,vector<vector<int>>&dp){
    //     if(target == 0){
    //         return 0;
    //     }
    //     if(index == coins.size()-1){
    //         return (target % coins[index]  == 0 ? target/coins[index] : 1e9);
    //     }

    //     if(dp[index][target] != -1 ){
    //         return dp[index][target];
    //     }

    //     int take = INT_MAX;
    //     if(target >= coins[index]){
    //         take = 1 + find(index,coins,target-coins[index],dp);
    //     }

    //     int notTake = find(index+1, coins,target,dp);

    //     return dp[index][target] = min(take,notTake);
    // }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> prev(amount + 1, 1e9);

        // base case
        prev[0] = 0;

        for (int index = 1; index <= coins.size(); index++)
        {
            vector<int> curr(amount + 1, 1e9);
            curr[0] = 0;
            for (int target = 1; target <= amount; target++)
            {
                int take = INT_MAX;
                if (coins[index - 1] <= target)
                {
                    take = 1 + curr[target - coins[index - 1]];
                }
                int notTake = prev[target];
                curr[target] = min(take, notTake);
            }

            prev = curr;
        }

        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};