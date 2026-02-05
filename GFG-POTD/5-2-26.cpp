#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
    
        int maxLen = 0;
    
        int zeros = 0;
    
        while(j < n){
            if(nums[j] == 0) zeros++;
            while(zeros > k){
                if(nums[i] == 0) zeros--;
                i++;
            }
    
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};
