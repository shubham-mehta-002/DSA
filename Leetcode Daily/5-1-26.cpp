#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        long long sum = 0;
        int minEl = INT_MAX;
        int neg = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                minEl = min(minEl,abs(matrix[i][j]));
                if(matrix[i][j] < 0)    neg++;
            }
        }
        cout<<minEl;
        if(neg%2 == 0){
            return sum;
        }else{
            return sum - 2*abs(minEl);
        }
    }
};