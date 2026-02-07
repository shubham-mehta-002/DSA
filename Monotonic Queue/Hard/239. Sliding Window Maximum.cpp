#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int i=0;
        int j=0;
        int n = nums.size();
        vector<int>res;
        while(j<n){
            // remove previous window values
            while(!dq.empty() && dq.front() < i){
                dq.pop_front();
            }

            // push 
            while(!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);

            // check for window size
            if(j-i+1 == k){
                res.push_back(nums[dq.front()]);
                i++;
            }
            ++j;
        }

        return res;
    }
};