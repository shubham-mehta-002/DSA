#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // int find(int currentIndex, vector<int>&height,vector<int>&mem){
    //     int n = height.size();
    //     if(currentIndex >= n){
    //         return INT_MAX;
    //     }
        
    //     if(currentIndex == n-1){
    //         return 0;
    //     }
    //     if(mem[currentIndex] != INT_MAX){
    //         return mem[currentIndex];
    //     }
    //     int skipOne = INT_MAX;
    //     int skipTwo = INT_MAX;
    //     if(currentIndex <= n-2){
    //         skipOne = abs(height[currentIndex+1] - height[currentIndex]) + find(currentIndex+1, height,mem);
    //     }
        
    //     if(currentIndex <= n-3){
    //         skipTwo = abs(height[currentIndex+2] - height[currentIndex]) + find(currentIndex+2, height,mem);
    //     }
        
    //     return mem[currentIndex] = min({
    //         skipOne,
    //         skipTwo
    //     });
    // }
    
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int>dp(n,INT_MAX);
        
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            dp[i] = min({
                abs(height[i+1] - height[i]) + dp[i+1],
                (i<= n-3 ? abs(height[i+2] - height[i]) + dp[i+2] : INT_MAX)
            });
        }
        // return find(0,height,mem);
        return dp[0];
    }
};