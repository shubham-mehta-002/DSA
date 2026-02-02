#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for(int el : nums){
            if(el == 1){
                count ++;
            }else{
                count = 0;
            }

            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};