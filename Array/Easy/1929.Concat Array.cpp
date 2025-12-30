//https://leetcode.com/problems/concatenation-of-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2*n);
        
        int i = 0;
        for(int el : nums){
            ans[i] = ans[i+n] = el;
            i++;
        }
        return ans;
    }
};