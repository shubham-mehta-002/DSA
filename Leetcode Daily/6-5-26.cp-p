#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>>res(m,vector<char>(n,'.'));

        for(int i=0;i<n;i++){
            int ptr = m-1;
            int j = m-1;
            while(j>=0){
                if(boxGrid[i][j] == '.'){
                    continue;
                }

                if(boxGrid[i][j] == '*'){
                    res[j][n-i-1] = '*';
                    ptr = j-1;
                }

                if(boxGrid[i][j] == '#'){
                    res[ptr][n-i-1] = '#';
                    ptr--;
                }
                j--;
            }
        }

        return res;
    }
};