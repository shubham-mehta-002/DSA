#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int>dx = {0,-1,0,1};
    vector<int>dy = {1,0,-1,0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i = 0 ;i <m ;i++){
            for(int  j= 0; j<n ;j++){
                if(mat[i][j] == 0){
                    dist[i][j]=0;
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }


        while(!q.empty()){
            pair<int,int>&p = q.front();
            for(int i = 0; i< 4; i++){
                int new_r = p.first + dx[i];
                int new_c = p.second + dy[i];

                if(new_r>=0 && new_c>=0 && new_r <m && new_c<n && !vis[new_r][new_c]){
                        dist[new_r][new_c] = 1 + dist[p.first][p.second];
                        q.push({new_r,new_c});
                        vis[new_r][new_c] = 1;
                }
            }
            q.pop();
        }
        
        return dist;
    }
};


//https://leetcode.com/problems/01-matrix/