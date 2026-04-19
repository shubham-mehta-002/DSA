#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = n1-1;
        int j = n2-1;

        int maxx = 0;
        while(i >=0 && j >=0){
            while(j>=0 && nums1[i] > nums2[j]){
                j--;
            }

            if(j >=0 && i<=j){
                maxx = max(maxx, j-i);
            }
            i--;
        }
        return maxx;
    }
};