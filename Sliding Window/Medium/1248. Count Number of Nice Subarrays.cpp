#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int noOfSubarraysHavinglessThanKOdds(vector<int>&nums, int k){
        int i = 0;
        int j = 0;
        int n = nums.size();

        int odds = 0;
        int count = 0;

        while(j<n){
            if(nums[j] % 2 != 0){
                odds++;
            }

            while(odds > k){
                if(nums[i] % 2 != 0){
                    odds--;
                }
                i++;
            }

            count += (j-i+1);
            j++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return noOfSubarraysHavinglessThanKOdds(nums,k) - noOfSubarraysHavinglessThanKOdds(nums,k-1);
    }
};