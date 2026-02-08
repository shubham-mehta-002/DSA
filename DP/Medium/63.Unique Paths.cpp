#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // int find(int row, int col, vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();

    //     if(row >=m || col >= n){
    //         return 0;
    //     }

    //     if(obstacleGrid[row][col] == 1){
    //         return 0;
    //     }

    //     if(row == m-1 && col == n-1){
    //         return 1;
    //     }

    //     if(dp[row][col] != -1){
    //         return dp[row][col];
    //     }

    //     int total = 0;

    //     // bottom
    //     total += find(row+1,col,obstacleGrid,dp);

    //     // right
    //     total += find(row,col+1,obstacleGrid,dp);

    //     return dp[row][col] = total;

    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1){
            return 0;
        }

        // vector<vector<int>>dp(m, vector<int>(n,-1));
        vector<int>prev(n,0);
    
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0){
                    curr[0] = 1;
                    continue;
                }

                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                }else{
                    int total = 0;
                    
                    // top
                    if(i > 0){
                        total += prev[j];
                    }

                    // left
                    if(j > 0){
                        total += curr[j-1];
                    }

                    curr[j] = total;
                }

            }
            prev = curr;
        }        

        return prev[n-1];
    }
};