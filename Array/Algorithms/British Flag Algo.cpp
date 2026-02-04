//https://leetcode.com/problems/sort-colors/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = -1;
        int one = 0;
        int two = n-1;
    
        while(one <= two){
            int val = nums[one];

            if(val == 1){
                one++;
            }else if(val == 2){
                swap(nums[two],nums[one]);
                two--;
            }else{
                swap(nums[zero+1],nums[one]);
                zero++;
                one++;
            }
        }

    }
};