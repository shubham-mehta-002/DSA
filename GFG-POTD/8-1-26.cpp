#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int find(vector<int>&arr, int k){
        int i = 0;
        int j= 0 ;
        int count = 0;
        int n = arr.size();
        int odds = 0;
        
        while(j<n){
            if(arr[j] %2 == 1){
                odds++;
            }    
            
            
            while(odds>k){
                if(arr[i] % 2 == 1){
                    odds--;
                }
                i++;
            }
            
            count+=(j-i+1);
            j++;
        }
        
        return count;
    }
    
    int countSubarrays(vector<int>& arr, int k) {
        return find(arr,k) - find(arr,k-1);
    }
};