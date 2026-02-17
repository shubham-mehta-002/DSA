#include<bits/stdc++.h>
using namespace std;
class Solution {    
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        int n = arr.size();
 
        int maxLen = 0;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            int val = arr[i];
            
            sum += val;
            
            if(sum == k){
                maxLen = max(maxLen, i+1);
            }
            

            int diff = sum-k;
                
            if(m.find(diff)!=m.end()){
                maxLen = max(maxLen, i-m[diff]);
            }
                
            if(m.find(sum) == m.end()){
                m[sum] = i;
            }
        }
        
        return maxLen;
        
    }
};