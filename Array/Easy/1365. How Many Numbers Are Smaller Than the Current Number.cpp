// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>res;
        vector<int>freq(101,0);

        for(int el : nums){
            freq[el]++;
        }

        // prefix
        int count = 0;
        for(int i=0;i<=100;i++){
            int val = freq[i];
            freq[i] = count;
            count += val;
        }

        // make result array
        for(int el: nums){
            res.push_back(freq[el]);
        }

        return res;
    }
};