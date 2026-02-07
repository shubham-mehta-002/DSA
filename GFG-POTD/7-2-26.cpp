#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int i = 0;
        int j = n-1;
        
        int totalSum = 0;
        int currSum = 0;
        
        for(int i=0;i<n;i++){
            currSum += (i*arr[i]);
            totalSum += arr[i];
        }
        
        
        int maxSum = currSum;
        
        while(j>=0){
            
            currSum = (currSum - arr[j]*(n-1) + totalSum - arr[j]);
            maxSum = max(maxSum , currSum); 
            j--;
        }
        
        
        return maxSum;
    }
};