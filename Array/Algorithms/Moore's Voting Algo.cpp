//https://leetcode.com/problems/majority-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;

        for(int n : nums){
            if(count == 0){
                candidate = n;
                count = 1;
            }else if(n == candidate){
                count++;
            }else{
                if(count == 1){
                    candidate = -1;
                }
                count --;
            }
        }

        return candidate;
    }
};