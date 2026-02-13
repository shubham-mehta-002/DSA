#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverse(int low, int high, vector<int>&nums){
        int n = high-low+1;
        for(int i=0; i<n/2; i++){
            // swap
            nums[low+i] = nums[low+i] ^ nums[high-i];
            nums[high-i] = nums[low+i] ^ nums[high-i];
            nums[low+i] = nums[low+i] ^ nums[high-i];
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        reverse(0,n-1,nums);
        reverse(0,k-1,nums);
        reverse(k,n-1,nums);
    }
};