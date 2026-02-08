#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<int>prev(sum+1,0);
        
        // base case
        if(sum >= arr[0]){
            prev[arr[0]] = 1;
        }
                
        prev[0] = 1;
        
        for(int index=1;index<arr.size();index++){
            vector<int>curr(sum+1,0);
            curr[0] = 1;
            for(int target = 1; target<=sum; target++){
                // notTake
                int notTake = prev[target];
                
                int take = 0;
                if(target >= arr[index]){
                    take = prev[target-arr[index]];
                }
                
                curr[target] = take || notTake;
            }
            
            prev = curr;
        }
        
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums){
            total += n;
        }

        if(total % 2 != 0)  return false;

        int target = total/2;

        return isSubsetSum(nums,target);
    }
};