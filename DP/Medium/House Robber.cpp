#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int find(int index, vector<int>&nums, vector<int>&mem){
    //     if(index < 0){
    //         return 0;
    //     }
    //     if(index == 0){
    //         return nums[0];
    //     }
    //     if(mem[index] != -1){
    //         return mem[index];
    //     }
    //     int notTake = find(index - 1, nums,mem);
    //     int take = nums[index] + find(index-2,nums,mem);
    //     return mem[index] = max(take,notTake);
    // }
    int rob(vector<int>& nums) {
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
};