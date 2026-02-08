#include<bits/stdc++.h>
using namespace std;


// class Solution {
  
// public:
//     int find(int row, int col, vector<vector<int>>&triangle,vector<vector<int>>&dp){
//         if(row >= triangle.size()){
//             return 0;
//         }
//         if(dp[row][col] != INT_MAX){
//             return dp[row][col];
//         }
      
//         int minSum = INT_MAX;
//         // bottom
//         minSum = min(minSum, triangle[row][col] + find(row+1, col, triangle,dp));

//         // bottom-right;
//         minSum = min(minSum, triangle[row][col] + find(row+1, col+1, triangle,dp));

//         return dp[row][col] = minSum;
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         vector<vector<int>>dp;
//         for(auto row : triangle){
//             dp.push_back(vector<int>(row.size(),INT_MAX));
//         }

//         dp[0][0] = triangle[0][0];
//         for(int i=1;i<triangle.size();i++){
//             for(int j=0;j<triangle[i].size();j++){
//                 int minSum = INT_MAX;
//                 // up
//                 if(j != triangle[i].size()-1){
//                     minSum = min(minSum, dp[i-1][j]);
//                 }

//                 // up-left
//                 if(j > 0){
//                     minSum = min(minSum, dp[i-1][j-1]);
//                 }
//             dp[i][j] = minSum + triangle[i][j];
//             }

//         }


//         int n = dp.size();
//         int minVal = INT_MAX;

//         for(int i=0;i<dp[n-1].size();i++){
//             minVal = min(minVal, dp[n-1][i]);
//         }

//         return minVal;
//         // return find(0,0,triangle,dp);
//     }
// };

// spaced optimized soln
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(triangle[n-1].size(),INT_MAX);

        dp[0] = triangle[0][0];

        for(int row = 1;  row<n; row++){
            for(int col = triangle[row].size()-1; col >=0 ; col--){
                int minVal = INT_MAX;
                if(col < row){
                    minVal = min(minVal , dp[col]);
                }

                if(col > 0){
                    minVal = min(minVal, dp[col-1]);
                }

                dp[col] = triangle[row][col] + minVal;
            }
        }

        int minVal = INT_MAX;
        for(int i=0;i<dp.size();i++){
            minVal = min(minVal, dp[i]);
        }

        return minVal;

    }
};