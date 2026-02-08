#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // int find(int row, int col, vector<vector<int>>& matrix,vector<vector<int>>&dp){
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     if(row >= m || col >= n || col < 0 || row < 0){
    //         return INT_MAX;
    //     }

    //     if(row == m-1){
    //         return matrix[row][col];
    //     }

    //     if(dp[row][col] != INT_MAX){
    //         return dp[row][col];
    //     }

    //     int minSum = INT_MAX;

    //     // bottom -left
    //     minSum = min({
    //        minSum,
    //        find(row+1,col-1,matrix,dp)
    //     });

    //     // bottom
    //     minSum = min({
    //         minSum,
    //         find(row+1,col,matrix,dp)
    //     });

    //     // bottom-right
    //     minSum = min({
    //         minSum,
    //         find(row+1,col+1,matrix,dp)
    //     });
        
    //     return dp[row][col] = matrix[row][col] + minSum;
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>prev(n,0);

        // base case
        for(int i=0;i<n;i++){
            prev[i] = matrix[0][i];
        }

        for(int row=1;row<m;row++){
            vector<int>curr(n,INT_MAX);
            for(int col=0;col<n;col++){
                int minSum = INT_MAX;
                if(col > 0){
                    minSum = min(minSum , prev[col-1]);
                }

                minSum = min(minSum , prev[col]);

                if(col < n-1){
                    minSum = min(minSum, prev[col+1]);
                }
                curr[col] = matrix[row][col] + minSum;
            }
            prev = curr;
        }

        int minSum = INT_MAX;
        for(int i=0;i<n;i++){
            minSum = min({
                minSum,
                prev[i]
            });
        }

        return minSum;
    }
};