#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int current, int n,vector<int>&dp){
        if(current == n){
            return 1;
        }
        if(current > n){
            return 0;
        }
        if(dp[current] != -1){
            return dp[current];
        }
        int total = 0;

        total += find(current+1,n,dp);
        total += find(current+2,n,dp);

        return dp[current] = total;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[n] = 1;
        dp[n-1] = 1;
        for(int i = n-2; i>=0; i--){
            int total = 0;
            total += dp[i+1];
            total += dp[i+2];

            dp[i] = total;
        } 

        return dp[0];
        // return find(0,n,dp);
    }
};