#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int n){
        int i = 0;
        while(i<32){
            // find if the bit is set
            bool isBitSet = ((1 << i) & n) > 0;
            // when 0 is encountered
            if(!isBitSet){
                break;
            }
            ++i;
        }

        int prevSetBit = i-1;
        // case : when the 0th bit was not set -> so no possible number is there ie the number is not odd so not prime
        if(prevSetBit == -1){
            return -1;
        }
        // now make this bit -> setBit
        int number = (1 << prevSetBit) ^ n;
        return number;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(int n : nums){
            res.push_back(find(n));
        }
        return res;
    }
};