#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(int row, int col, vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row < 0 || col < 0){
            return INT_MAX;
        }

        if(row == 0 && col == 0){
            return grid[0][0];
        }

        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }

        int up = INT_MAX;
        int left = INT_MAX;
        // up
        up = findMin(row-1,col,grid,dp); 
        
        // left
        left = findMin(row,col-1,grid,dp); 

        return dp[row][col] = grid[row][col] + min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>>dp(m, vector<int>(n,INT_MAX));
        // return findMin(m-1,n-1, grid,dp);

        vector<int>prev(n,INT_MAX);
        prev[0] = grid[0][0];
        for(int i=1;i<n;i++){
            prev[i] = grid[0][i] + prev[i-1]; 
        }

        for(int row = 1; row < m ; row++){
            // vector<int>curr(n,INT_MAX);
            for(int col = 0 ;col<n;col++){
                if(row == 0 && col == 0){
                    continue;
                }
                
                int up = INT_MAX;
                int left = INT_MAX;

                // up
                if(row > 0){
                    up = prev[col]; 
                }
                
                // left
                if(col > 0){
                    left = prev[col-1]; 
                }

                prev[col] = grid[row][col] + min(up,left);
            }

            // prev=curr;
        }

        return prev[n-1];
    }
};