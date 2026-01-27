#include<bits/stdc++.h>
using namespace std;    
class Solution {
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,1,0,-1};
    
  public:
    bool find(int row, int col, vector<vector<char>> &mat, string &word, int index, vector<vector<int>>&vis){
        int m = mat.size();
        int n = mat[0].size();
        
        if(index >= word.size()){
            return true;
        }
        
        // check for all 4 adj cells    
        for(int i=0;i<4;i++){
            int new_r = row + dx[i];
            int new_c = col + dy[i];
            
            if(new_r >=0  && new_c>=0 && new_r < m && new_c < n && word[index] == mat[new_r][new_c] && !vis[new_r][new_c] ){
                vis[new_r][new_c] = 1;
                if(find(new_r, new_c, mat, word, index+1, vis)){
                    return true;
                }
                vis[new_r][new_c] = 0;
            }
        }
        
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0] == mat[i][j]){
                    vis[i][j] = 1;
                    if(find(i,j,mat,word,1,vis)){
                        return true;
                    }
                     vis[i][j] = 0;
                }
            }
        }
        
        return false;
    }
};