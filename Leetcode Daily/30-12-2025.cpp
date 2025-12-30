#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidGrid(int i, int j, vector<vector<int>>&grid){
        vector<int>seen(10,0);
        for(int a = 0;a<3;a++){
            for(int b=0;b<3;b++){
                int val = grid[i+a][j+b];
                if(val < 1 || val > 9)    return false;
                if(seen[val])    return false;
                seen[val] = 1;
            }
        }

        int r1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        int r2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int r3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

        if(!(r1 == r2 && r2 == r3)){
            return false;
        } 
        int c1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int c2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int c3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];

        if(!(c1 == c2 && c2 == c3)){
            return false;
        }

        int d1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int d2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
        
        if(d1 != d2 || d1 != r1 || d1!= c1){
            return false;
        }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        if(m*n < 9){
            return 0;
        }

        int rowsum = 0;
        int colsum = 0;
        int j = 0;
        int i = 0;
        while(i<m-2){
            j = 0;
            while(j<n-2){
                count += isValidGrid(i,j,grid) ? 1 : 0;
                j++;
            }
            i++;
        }

        return count;
    }   
};