// https://leetcode.com/problems/maximum-subarray/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;

        for(int n : nums){
            if(sum < 0) {
                sum = 0;
            }

            sum += n;

            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
};