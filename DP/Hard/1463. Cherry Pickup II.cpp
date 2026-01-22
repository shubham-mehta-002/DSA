#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int row = 0;
        int c1 = 0;
        int c2 = n-1;
        // vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        vector<vector<int>>prev(n,vector<int>(n,INT_MIN));

        // base case
        prev[0][n-1] = (0 == n-1 ? grid[0][0] : grid[0][0] + grid[0][n-1]);

        // iteration
        for(int row=1;row<m;row++){
            vector<vector<int>>curr(n,vector<int>(n,INT_MIN));
            for(int c1=0;c1<n;c1++){
                for(int c2=0;c2<n;c2++){
                    int count = 0;

                    if(c1 == c2){
                        count += grid[row][c1];
                    }else{
                        count += (grid[row][c1] + grid[row][c2]);
                    }

                    int maxPick = INT_MIN;
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            if(c1+i >= n || c2+j >= n || c1+i <0 || c2+j < 0)   continue;
                            maxPick = max(maxPick , prev[c1+i][c2+j]);
                        }
                    }

                    if(maxPick == INT_MIN)  continue;
                    curr[c1][c2] = (count + maxPick );
                }
            }
                prev = curr;
        }    

        int maxVal = 0;
        for(int c1=0;c1<n;c1++){
            for(int c2=0;c2<n; c2++){
                maxVal = max(maxVal , prev[c1][c2]);
            }
        }

        return maxVal;

    }
};