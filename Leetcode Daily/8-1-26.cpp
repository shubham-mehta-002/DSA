#include<bits/stdc++.h>
using namespaces std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int>next(m+1,-1e9);

        for(int i = n-1 ; i>=0 ; i--){
            vector<int>curr(m+1,-1e9);

            for(int j = m-1; j>=0 ; j--){
                int take = nums1[i] * nums2[j];
                int remainingElementsResult = next[j+1];

                take = max(take,take+remainingElementsResult);
                
                // not take
                int moveI = next[j];
                int moveJ = curr[j+1];

                curr[j]= max({
                    take,
                    moveI,
                    moveJ
                }); 
            }

            next = curr;
        }
        return next[0];
    }
};