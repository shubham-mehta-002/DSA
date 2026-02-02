#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();

        while(j<n){
            while(j<n && nums[i] == nums[j]){
                j++;
            }
            if(j >=n ) break;
            nums[++i] = nums[j++];
        }

        return i+1;
    }
};