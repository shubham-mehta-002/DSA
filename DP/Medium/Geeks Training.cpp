#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:

    int maximumPoints(vector<vector<int>>& arr) {
        int m = arr.size();
        
        // vector<vector<int>>dp(m, vector<int>(3,0));
        vector<int>prev(3,0);
        
        // base case
        prev[0] = arr[0][0];  
        prev[1] = arr[0][1];
        prev[2] = arr[0][2];
        
        
        for(int row = 1; row < m; row ++){
            vector<int>curr(3,0);
            
            for(int col = 0; col < 3 ; col++){
                int maxPoints = INT_MIN;
                for(int i=0;i<3;i++){
                    maxPoints = max({
                        maxPoints,
                        (col == i ? 0 : prev[i])
                    });
                    
                    curr[col] = arr[row][col] + maxPoints;
                }
            }
            
            prev = curr;
        }
        
    
        
        int maxVal =INT_MIN;
        for(int i = 0;i<3;i++){
            maxVal = max(maxVal ,prev[i]);
            // cout << dp[m-1][i]<<" ";
        }
        return maxVal;
    }
};