#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(vector<int>&nums, int target){
        if(target < 0) return 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int count = 0;
        int sum = 0;
        while(j<n){
            sum += nums[j];

            while(sum > target){
                sum -= nums[i];
                i++;
            }

            count+=(j-i+1);
            j++;
        }
        return count;

    }

    int numSubarraysWithSum(vector<int>& nums, int k) {
        return find(nums,k) - find(nums,k-1);
    }
};