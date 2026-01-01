#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res;
        int carry = 1;
        for(int i= digits.size()-1 ; i>=0 ;i--){
            int sum = digits[i] + carry;
            int rem = sum%10;
            carry = sum/10;
            res.insert(res.begin(),rem);
        }
        if(carry){
            res.insert(res.begin(),carry);
        }
        return res;
    }
};