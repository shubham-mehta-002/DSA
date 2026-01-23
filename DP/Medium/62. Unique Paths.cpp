#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // int find(int row, int col, int m, int n){
    //     if(row >=m || col >=n){
    //         return 0;
    //     }
    //     if(row == m-1 && col == n-1){
    //         return 1;
    //     }

    //     return (
    //         find(row+1,col,m,n) + 
    //             find(row,col+1,m,n)
    //     );
    // }
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){

                if(i==0 && j==0){
                    curr[0] = 1;
                    continue;
                }

                int total = 0;
                // left
                if(j > 0){
                    total += curr[j-1];
                }

                // up
                total += prev[j];

                curr[j] = total;
            }   

            prev = curr;
        }

        return prev[n-1];
    }
};