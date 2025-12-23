#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int>dx = {0,1,0,-1};
    vector<int>dy = {1,0,-1,0};

public:
    void traverse(vector<vector<int>>&image, int r, int c, int from, int to){
        int m = image.size();
        int n = image[0].size();

        image[r][c] = to; 
        
        for(int i = 0; i<4; i++){
            int new_r = r + dx[i];
            int new_c = c + dy[i];
            if(new_r>=0 && new_c>=0 && new_r<m && new_c<n && image[new_r][new_c]==from){
                traverse(image,new_r,new_c,from,to);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        // vector<vector<int>>vis(image.size(), vector<int>(image[0].size(),0));

        traverse(image,sr,sc,image[sr][sc],color);

        return image;
    }
};


// https://leetcode.com/problems/flood-fill/description/