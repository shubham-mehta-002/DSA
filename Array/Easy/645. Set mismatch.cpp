#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n+1,0);
        vector<int>res;
        int total = 0;
        for(int el : nums){
            if(vis[el] == 1){
                res.push_back(el);
            }else{
                vis[el] = 1;
                total+=el;
            }

        }

        res.push_back( (n*(n+1)/2) - total );
        return res;
    }
};