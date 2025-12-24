#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>dx = {-1,0,1,0};
    vector<int>dy ={ 0, -1,0,1};
public:
    void dfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int new_r = row + dx[i];
            int new_c = col + dy[i];
            if(new_r >=0 && new_c>=0 && new_r<m && new_c<n && !vis[new_r][new_c] && grid[new_r][new_c] == 1){
                dfs(grid,vis,new_r,new_c);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        // upper
        for(int c=0;c<n;c++){
            if(!vis[0][c] && grid[0][c] == 1){
                dfs(grid,vis,0,c);
            }
        }

        //lower
        for(int c=0;c<n;c++){
            if(!vis[m-1][c] && grid[m-1][c] == 1){
                dfs(grid,vis,m-1,c);
            }
        }

        //left
        for(int r=1;r<m-1;r++){
            if(!vis[r][0] && grid[r][0] == 1){
                dfs(grid,vis,r,0);
            }
        }

        //right
        for(int r=1;r<m-1;r++){
            if(!vis[r][n-1] && grid[r][n-1] == 1){
                dfs(grid,vis,r,n-1);
            }
        }
    
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};

//https://leetcode.com/problems/number-of-enclaves/description/