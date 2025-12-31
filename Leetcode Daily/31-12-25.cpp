#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};
public:
    void markLandAndWater(vector<vector<int>>&grid, vector<vector<int>>&cells,int mid){
        for(int i=0;i<=mid;i++){
            int r = cells[i][0]-1;
            int c = cells[i][1]-1;

            grid[r][c] = 1;
        }
    }
    bool dfs(vector<vector<int>>&grid, int row, int col){
        if(row==grid.size()-1){
            return true;
        }
        grid[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<4;i++){
            int new_r = row + dx[i];
            int new_c = col + dy[i];
            if(new_r >=0 && new_c >=0 && new_r < m && new_c < n && grid[new_r][new_c]==0){
                if(dfs(grid,new_r,new_c)){
                    return true;
                }
            }
        }
        return false;
    }
    bool canCross(vector<vector<int>>&cells, int row, int col, int mid){
        // int m = grid.size();
        // int n = grid[0].size();
        vector<vector<int>>grid(row,vector<int>(col,0));
        markLandAndWater(grid,cells,mid);
        for(int j=0;j<col;j++){
            if(grid[0][j] == 0){
                if(dfs(grid,0,j)){
                    return true;
                }
            }
        }

        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int low = 0;
        int high = n-1;
        int day = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            bool found = canCross(cells,row,col,mid);
            if(found){
                day = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return day+1;
    }
};