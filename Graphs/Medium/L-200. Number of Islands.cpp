#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int>dx = {0,1,0,-1};
    vector<int>dy = {1,0,-1,0};
public:
    void traverse(vector<vector<char>>& grid , vector<vector<int>>&vis, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()){
            int size = q.size();
            while(size--){
                const pair<int,int>& top = q.front();
                for(int i = 0; i <4; i++){
                    int new_r = top.first + dx[i];
                    int new_c = top.second + dy[i];

                    if(new_r >=0 && new_c >=0  && new_r < m && new_c < n && grid[new_r][new_c] == '1' && !vis[new_r][new_c]){
                        vis[new_r][new_c] = 1;
                        q.push({new_r,new_c});
                    }
                }
                q.pop();
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        int islands = 0;

        for(int i = 0 ; i< m ; i++ ){
            for(int j= 0 ;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    vis[i][j] = 1;
                    islands++;
                    traverse(grid,vis,i,j);
                }
            }
        }

        return islands;
    }
};

//https://leetcode.com/problems/number-of-islands/description/