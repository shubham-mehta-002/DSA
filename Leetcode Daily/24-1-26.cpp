#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxVal = INT_MIN;
        int i=0;
        int j=nums.size()-1;

        while(j>i){
            maxVal = max(maxVal , nums[i] + nums[j]);
            i++;
            j--;
        }

        return maxVal;
    }
};