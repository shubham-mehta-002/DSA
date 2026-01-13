#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // int find(int n,vector<int>&mem){ 
    
    //     if(n == 0){
    //         return 0;
    //     }
    //     if(n == 1){
    //         return 1;
    //     }
        
    //     if(mem[n-1] != -1){
    //         return mem[n-1];
    //     }
        
    //     return mem[n-1] = (find(n-1,mem) + find(n-2,mem));
    // }
    int nthFibonacci(int n) {
        vector<int>dp(n+1,-1);
        // return find(n,mem);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};