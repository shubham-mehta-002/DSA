#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // int find(int currIdx, vector<int>&arr, vector<int>&dp){
    //     if(currIdx < 0)   return 0;
    //     if(dp[currIdx] != -1){
    //         return dp[currIdx];
    //     }
        
    //     int notTake = find(currIdx-1, arr, dp);
    //     int take = arr[currIdx] + find(currIdx-2,arr, dp);
            
    //     return dp[currIdx] = max({take,notTake});
    // }
    
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        vector<int>dp(arr.size(),-1);
        
        // return find(arr.size()-1,arr,dp);
        // dp[0] = arr[0];
        int prev2 = 0;
        int prev = arr[0];
        
        for(int i=1;i<arr.size();i++){
            int notTake = prev;
            int take = arr[i] + (i > 1 ? prev2 : 0);
            
            int curr = max(take,notTake);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};