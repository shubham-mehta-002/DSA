#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int i = 0 , j=0;
        int sum = 0;
        int maxSum = INT_MIN;
        
        while(j<arr.size()){
            sum+=arr[j];
            if(j-i+1 == k){
                maxSum = max(maxSum,sum);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        
        return maxSum;
    }
};