#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,int>m;
public:
    int find(int target){
        if(m.count(target)){
            return m[target];
        }

        for(int i=0;i<=target;i++){
            int val = i | i+1;

            if(m.count(val) == 0){
                m[val] = i;
            }

            if(val == target){
                return i;
            }
        }

        return m[target] = -1;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int n : nums){
            ans.push_back(find(n));
        }

        return ans;
    }
};