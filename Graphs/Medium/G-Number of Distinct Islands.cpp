#include <bits/stdc++.h>
using namespace std;
class Solution {
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
  public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, set<vector<pair<int,int>>> &st, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        
        vector<pair<int,int>> island;
        queue<pair<int,int>>q;
        q.push({row,col});
        
        
        while(!q.empty()){
            const pair<int,int>&top = q.front();
            q.pop();
            island.push_back({top.first-row,top.second-col});
            
            for(int i=0;i<4;i++){
                int newr = top.first + dx[i];
                int newc = top.second + dy[i];
                
                if(newr >=0 && newc >=0 && newr<m && newc<n && grid[newr][newc] == 1 && !vis[newr][newc]){
                    vis[newr][newc] = 1;
                    q.push({newr,newc});
                }
            }
        }
        
        st.insert(island);
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> st;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vis[i][j] = 1;
                    bfs(grid,vis,st,i,j);
                } 
            }
        }
        
        
        return st.size();
    }
};
