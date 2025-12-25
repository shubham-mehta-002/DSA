//https://leetcode.com/problems/maximize-happiness-of-selected-children/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end() ,[](int a, int b){
            return a > b;
        });

        int sadness = 0;
    
        long long sum = 0;
        for(int i=0;i<k;i++){
            sum += max(0,happiness[i]-sadness);
            sadness++;
        }

        return sum;

    }
};