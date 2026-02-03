#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1;
        int n = nums.size();

        // increase
        while(i<n && nums[i] > nums[i-1]){
            i++;
        }

        if(i == 1 || i==n || nums[i] == nums[i-1]){
            return false;
        }


        // decrease
        while(i<n && nums[i] < nums[i-1]){
            i++;
        }

        if(i == n || nums[i] == nums[i-1]){
            return false;
        }

        // increase
        while(i<n && nums[i] > nums[i-1]){
            i++;
        }

        if(i < n){
            return false;
        }

        return true;
    }
};