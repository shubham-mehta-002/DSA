#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>suffix(n,-1);

        int minn=INT_MAX;
        for(int i=n-1;i>=0;i--){
            minn = min(minn, nums[i]);
            suffix[i] = minn;
        }

        int maxx = INT_MIN;
        for(int i=0;i<n;i++){
            maxx = max(maxx, nums[i]);

            if(maxx - suffix[i] <=k){
                return i;
            }
        }

        return -1;
    }
};