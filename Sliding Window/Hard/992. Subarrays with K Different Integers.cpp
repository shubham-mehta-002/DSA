#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(vector<int>&nums, int k){
        if( k < 0)  return 0;

        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int,int>m;

        int count = 0;
        while(j<n){
            m[nums[j]]++;

            while(m.size() > k){
                m[nums[i]]--;
                if(m[nums[i]] == 0){
                    m.erase(nums[i]);
                }
                i++;
            }

            count += (j-i+1);
            j++;
        }
        return count;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find(nums,k) - find(nums,k-1);
    }
};