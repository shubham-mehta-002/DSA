#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxReach(n, -1);

        // Build max reach for each start position
        for (int i = 0; i < n; i++) {
            if (arr[i] == -1) continue;
            int l = max(0, i - arr[i]);
            int r = min(n - 1, i + arr[i]);
            maxReach[l] = max(maxReach[l], r);
        }

        int count = 0;
        int currEnd = -1;
        int farthest = -1;
        
        if(maxReach[0] == -1){
            return -1;
        }

        for(int i=0;i<n;i++){
            farthest = max(farthest, maxReach[i]);
            if(i > farthest) return -1;
            
            if(currEnd >= i){
                continue;
            }else{
                currEnd = farthest;
                count++;
            }
        }
        
        return count;
    }
};
