#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        int count = 0;
        
        unordered_map<int,int>m;
        int unique = 0;
        
        while(j < n){
            
            if(m[arr[j]] == 0){
                unique++;
            }
            m[arr[j]]++;
            
            while(unique > k){
                m[arr[i]]--;
                if(m[arr[i]] == 0){
                    unique--;
                }
                i++;
            }
                
            if(unique <= k){
                count += (j-i+1);    
                j++;
            }
            
        }
        
        return count;
        
    }
};