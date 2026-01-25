#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int find(int index, int openCount, int n,vector<vector<int>>&dp){
        if(index == n-1){
            return (openCount == 0);
        }
        
        if(openCount < 0 || openCount > n/2){
            return 0;
        }
        
        
        if(dp[index][openCount] != -1){
            return dp[index][openCount]; 
        }
        
        int count = 0;
        // open
        count+= find(index+1, openCount+1, n,dp);
        
        // close
        count += find(index+1, openCount-1, n,dp);
        
        return dp[index][openCount]  = count;
    }
    
    // int findWays(int n) {
    //     if(n % 2 != 0){
    //         return 0;
    //     }
    //     vector<vector<int>>dp(n, vector<int>((n/2)+1,0));
        
    //     // base case
    //     dp[n-1][0] = 1;
     
    //     for(int index = n-2; index>=0; index--){
    //         for(int openCount = 0; openCount <= n/2; openCount++){
    //             int count = 0;
    //             if(openCount < n/2) count += dp[index+1][openCount+1];
    //             if(openCount > 0) count += dp[index+1][openCount-1];
                
    //             dp[index][openCount] = count;
    //         }
    //     }
        
    //     return dp[0][1];
    // }
    
    int findWays(int n) {
        if(n % 2 != 0){
            return 0;
        }
        vector<int>next((n/2)+1,0);
        
        // base case
        next[0] = 1;
     
        for(int index = n-2; index>=0; index--){
            vector<int>curr((n/2)+1,0);
            
            for(int openCount = 0; openCount <= n/2; openCount++){
                int count = 0;
                if(openCount < n/2) count += next[openCount+1];
                if(openCount > 0) count += next[openCount-1];
                
                curr[openCount] = count;
            }
            
            next = curr;
        }
        
        return next[1];
    }
};