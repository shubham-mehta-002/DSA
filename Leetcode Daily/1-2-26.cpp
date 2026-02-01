#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;

        for(int i=1;i<nums.size();i++){
            if(nums[i] < a && nums[i] < b){
                b = a;
                a = nums[i];
            }else if(b > nums[i]){
                b = nums[i];
            }
        }

        return nums[0]+a+b;
    }
};