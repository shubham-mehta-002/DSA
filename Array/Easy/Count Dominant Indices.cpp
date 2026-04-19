#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int sum = nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            if((nums[i] * 1.0) > ((sum * 1.0) / (n-i-1))){
                count++;
            }        
            sum += nums[i];
        }

        return count;
    }
};