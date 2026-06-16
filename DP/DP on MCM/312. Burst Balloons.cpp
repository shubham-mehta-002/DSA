#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    // int find(int i, int j, vector<int>&nums,vector<vector<int>>&dp){
    //     if(i > j){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int maxx = INT_MIN;
    //     for(int k=i;k<=j;k++){
    //         maxx = max({
    //             maxx,
    //             nums[i-1]*nums[k]*nums[j+1] + find(i,k-1,nums,dp) + find(k+1,j,nums,dp)
    //         });
    //     }

    //     return dp[i][j] = maxx;
    // }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = i; j <= n; j++)
            {
                int maxx = INT_MIN;
                for (int k = i; k <= j; k++)
                {
                    maxx = max({maxx,
                                nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]});
                }

                dp[i][j] = maxx;
            }
        }

        return dp[1][n];
    }
};