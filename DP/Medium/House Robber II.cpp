#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int prev2 = 0;
        int prev = nums[0];

        for(int i = 1; i <nums.size() ; i++){
            int curr = max(nums[i] + prev2 , prev);
            prev2 = prev;
            prev = curr;
        }

        return prev; 
    }
    int rob(vector<int>& nums) {
        vector<int>temp1;
        vector<int>temp2;
        int n = nums.size();
        if(n==1)    return nums[0];

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
             if(i!=n-1) temp2.push_back(nums[i]);
        }

        return max({
            find(temp1),
            find(temp2)
        });
    }
};