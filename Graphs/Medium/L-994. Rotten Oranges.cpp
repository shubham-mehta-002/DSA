#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>dx = {0,1,0,-1};
    vector<int>dy = {1,0,-1,0};
public:
    int bfs(vector<vector<int>>& grid , vector<vector<int>>&vis,queue<pair<int,int>>&q){
        int m = grid.size();
        int n = grid[0].size();

        int time = 0;

        
        while(!q.empty()){
            int size = q.size();
            time++;
            while(size--){
                pair<int,int>&p = q.front();

                for(int i= 0 ;i<4; i++){
                    int nrow = p.first + dx[i];
                    int ncol = p.second + dy[i];

                    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                        vis[nrow][ncol]=1;
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                    }
                }
                q.pop();
            }
        }

        return time-1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
    
        for(int i = 0 ;i < m ; i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] == 0 && grid[i][j] == 2){
                    vis[i][j] = 1;
                    grid[i][j]=2;
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        if(!q.empty()){
            time = bfs(grid,vis,q);
        }

        for(int i = 0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};



// https://leetcode.com/problems/rotting-oranges/description/