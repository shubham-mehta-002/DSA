#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n,0);
        vector<int>res;

        for(int el : nums){
            vis[el-1] = 1;
        }

        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                res.push_back(i+1);
            }
        }

        return res;
    }
};