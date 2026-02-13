#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int counter = 0;

        int n = nums.size();

        for(int i=0;i<n-1;i++){
           if(nums[i] > nums[i+1]){
                counter++;
           } 
        }

        if((counter > 0 && nums[n-1] > nums[0] )||  counter > 1){
            return false;
        }

        return true;
    }
};