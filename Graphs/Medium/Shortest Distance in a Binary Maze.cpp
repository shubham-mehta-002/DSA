#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1,};

  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        using pp = pair<int,int>;
        int n = grid.size();
        int m = grid[0].size();
        
        // check
        if(grid[destination.first][destination.second] == 0 || grid[source.first][source.second] == 0) return -1;
        
        
        if(source == destination)   return 0;
        queue<pp>q;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second] = 0;
        q.push({source.first, source.second});
        
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
           
            for(int i=0;i<4;i++){
                int new_r = row + dx[i];
                int new_c = col + dy[i];
                
                if(new_r >=0 && new_c >=0 && new_r < n && new_c < m && grid[new_r][new_c] != 0 && dist[new_r][new_c] == INT_MAX){
                    dist[new_r][new_c] = 1 + dist[row][col];
                     
                    if(new_r == destination.first && new_c == destination.second){
                        return dist[new_r][new_c];
                    }
                    
                    q.push({new_r,  new_c});
                }
            }
        }
        
        return -1;
        
        
    }
};
