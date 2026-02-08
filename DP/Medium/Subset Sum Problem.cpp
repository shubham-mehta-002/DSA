#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // bool find(int n, vector<int>&arr, int target,vector<vector<int>>&dp){
    //     if(target == 0){
    //         return true;
    //     }
        
    //     if(n == 0){
    //         return target == arr[0];
    //     }
        
    //     if(dp[n][target] != -1){
    //         return dp[n][target];
    //     }
        
        
    //     // not take
    //     if(find(n-1,arr,target,dp)){
    //         return dp[n][target] = true;
    //     } 
        
    //     // take
    //     if(target >= arr[n] && find(n-1,arr,target-arr[n],dp)){
    //         return dp[n][target] = true;
    //     }
        
    //     return dp[n][target] = false;
    // }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // vector<vector<int>>dp(arr.size(),vector<int>(sum+1,0));
        vector<int>prev(sum+1,0);
        
        // base case
        if(sum >= arr[0]){
            prev[arr[0]] = 1;
        }
        
        // for(int i=0;i<arr.size();i++){
        //     dp[i][0] = 1; //target->0 for all values is true 
        // }
        
        prev[0] = 1;
        
        for(int index=1;index<arr.size();index++){
            vector<int>curr(sum+1,0);
            curr[0] = 1;
            for(int target = 1; target<=sum; target++){
                // notTake
                int notTake = prev[target];
                
                int take = 0;
                if(target >= arr[index]){
                    take = prev[target-arr[index]];
                }
                
                curr[target] = take || notTake;
            }
            
            prev = curr;
        }
        
        return prev[sum];
        // return find(arr.size()-1, arr,sum,dp);
    }
};