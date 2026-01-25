#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0;
        int j=0;
        int n = nums.size();
        int minVal = INT_MAX;
        while(j<n){
            while(j-i+1 != k){
                j++;
            }

            if(j >= n){
                break;
            }
            
            minVal = min(minVal , nums[j] - nums[i]);
            i++;
        }

        return minVal;
    }
};